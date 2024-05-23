#include <iostream>
#include <vector>
#include <cmath>

// Functie pentru exponentiere modulara
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    // Cheia privata
    long long d = 117;
    long long n = 391;

    // Mesajul criptat in blocuri
    std::vector<long long> cipher_blocks = {4, 1, 12, 12, 0, 0, 5, 14, 12, 11, 27, 4, 1, 0, 8, 7, 8};

    // Decriptare
    std::vector<long long> plain_blocks;
    for (auto block : cipher_blocks) {
        plain_blocks.push_back(mod_exp(block, d, n));
    }

    // Alfabetul folosit
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?!.";

    // Convertire blocuri numerice in text
    std::cout << "Mesaj decriptat: ";
    for (auto block : plain_blocks) {
        if (block < alphabet.size()) {
            std::cout << alphabet[block];
        } else {
            std::cout << "?"; // Pentru blocurile care nu se incadreaza in alfabet
        }
    }
    std::cout << std::endl;

    return 0;
}
