#include <iostream>
#include <vector>
#include <algorithm>

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

// Funcție pentru determinarea inversului modular
long long mod_inverse(long long a, long long m) {
    a = a % m;
    for (long long x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

void merkle_hellman_generate_keys(std::vector<long long> &v, long long &m, long long &a, long long &b, std::vector<long long> &w) {
    long long sum_v = 0;
    for (auto vi : v) {
        sum_v += vi;
    }

    std::cout << "Introduceți un modul m > " << sum_v << ": ";
    std::cin >> m;

    std::cout << "Introduceți un multiplicator a astfel încât cmmdc(a, m) = 1: ";
    std::cin >> a;

    b = mod_inverse(a, m);
    std::cout << "Inversul multiplicatorului b: " << b << std::endl;

    for (auto vi : v) {
        w.push_back((a * vi) % m);
    }

    std::cout << "Șirul public w: ";
    for (auto wi : w) {
        std::cout << wi << " ";
    }
    std::cout << std::endl;
}

long long merkle_hellman_encrypt(std::vector<long long> &w, std::vector<int> &message) {
    long long c = 0;
    for (size_t i = 0; i < w.size(); i++) {
        c += message[i] * w[i];
    }
    return c;
}

std::vector<int> merkle_hellman_decrypt(long long c, std::vector<long long> &v, long long m, long long b) {
    long long V = (b * c) % m;
    std::vector<int> message(v.size(), 0);

    for (int i = v.size() - 1; i >= 0; i--) {
        if (V >= v[i]) {
            message[i] = 1;
            V -= v[i];
        }
    }

    return message;
}

int main() {
    std::vector<long long> v = {2, 3, 7, 11, 21, 42}; // Un șir supercrescător
    long long m, a, b;
    std::vector<long long> w;

    merkle_hellman_generate_keys(v, m, a, b, w);

    std::vector<int> message = {1, 0, 1, 0, 1, 0}; // Mesaj binar de criptat
    long long c = merkle_hellman_encrypt(w, message);
    std::cout << "Mesaj criptat: " << c << std::endl;

    std::vector<int> decrypted_message = merkle_hellman_decrypt(c, v, m, b);
    std::cout << "Mesaj decriptat: ";
    for (auto bit : decrypted_message) {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;
}
