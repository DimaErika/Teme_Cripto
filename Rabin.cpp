#include <iostream>
#include <vector>
#include <cmath>

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

void rabin_generate_keys(long long &n, long long &p, long long &q) {
    std::cout << "Introduceți p și q (numere prime mari): ";
    std::cin >> p >> q;
    n = p * q;
    std::cout << "Cheia publică (n): " << n << std::endl;
    std::cout << "Cheia privată (p, q): (" << p << ", " << q << ")" << std::endl;
}

long long rabin_encrypt(long long m, long long n) {
    return (m * m) % n;
}

std::vector<long long> rabin_decrypt(long long c, long long p, long long q, long long n) {
    long long r1 = mod_exp(c, (p + 1) / 4, p);
    long long r2 = p - r1;
    long long s1 = mod_exp(c, (q + 1) / 4, q);
    long long s2 = q - s1;

    long long u = mod_inverse(p, q);
    long long v = mod_inverse(q, p);

    long long x1 = (r1 * q * v + s1 * p * u) % n;
    long long x2 = (r1 * q * v + s2 * p * u) % n;
    long long x3 = (r2 * q * v + s1 * p * u) % n;
    long long x4 = (r2 * q * v + s2 * p * u) % n;

    return {x1, n - x1, x2, n - x2};
}

int main() {
    long long n, p, q;
    rabin_generate_keys(n, p, q);

    long long m;
    std::cout << "Introduceți mesajul (număr întreg): ";
    std::cin >> m;

    long long c = rabin_encrypt(m, n);
    std::cout << "Mesaj criptat: " << c << std::endl;

    std::vector<long long> decrypted_messages = rabin_decrypt(c, p, q, n);
    std::cout << "Mesajele decriptate sunt: ";
    for (auto msg : decrypted_messages) {
        std::cout << msg << " ";
    }
    std::cout << std::endl;

    return 0;
}
