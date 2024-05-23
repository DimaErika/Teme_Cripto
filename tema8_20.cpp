#include <iostream>
#include <cmath>
#include <vector>
#include <string>

// Functie pentru exponentiere modulara
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Alfabetul utilizat
std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?!.";

int main() {
    // Parametrii cheilor
    unsigned long long p = 65537;
    unsigned long long g = 5;
    unsigned long long a = 13908;
    
    // Mesajul criptat
    unsigned long long u = 29095;
    unsigned long long v = 23846;
    
    // Decriptare
    unsigned long long w = mod_exp(u, p - 1 - a, p);
    unsigned long long m = (v * w) % p;

    // Convertire numar decriptat in blocuri de caractere
    std::vector<int> blocks;
    while (m > 0) {
        blocks.push_back(m % 30);
        m /= 30;
    }
    std::reverse(blocks.begin(), blocks.end());

    // Afisare mesaj decriptat
    std::cout << "Mesaj decriptat: ";
    for (auto block : blocks) {
        if (block < alphabet.size()) {
            std::cout << alphabet[block];
        } else {
            std::cout << "?"; // Pentru blocurile care nu se incadreaza in alfabet
        }
    }
    std::cout << std::endl;

    return 0;
}
