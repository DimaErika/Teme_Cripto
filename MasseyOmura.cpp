#include <iostream>

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

void massey_omura_generate_keys(long long p, long long &e, long long &d) {
    std::cout << "Introduceți exponentul secret e: ";
    std::cin >> e;
    d = mod_inverse(e, p - 1);
    std::cout << "Exponentul invers d: " << d << std::endl;
}

int main() {
    long long p, e_A, d_A, e_B, d_B;
    std::cout << "Introduceți numărul prim p: ";
    std::cin >> p;

    std::cout << "Generarea cheilor pentru Alice..." << std::endl;
    massey_omura_generate_keys(p, e_A, d_A);

    std::cout << "Generarea cheilor pentru Bob..." << std::endl;
    massey_omura_generate_keys(p, e_B, d_B);

    long long m;
    std::cout << "Introduceți mesajul (număr întreg): ";
    std::cin >> m;

    // Bob criptează mesajul și trimite lui Alice
    long long C1 = mod_exp(m, e_B, p);
    std::cout << "C1 (trimis de Bob lui Alice): " << C1 << std::endl;

    // Alice criptează mesajul și trimite lui Bob
    long long C2 = mod_exp(C1, e_A, p);
    std::cout << "C2 (trimis de Alice lui Bob): " << C2 << std::endl;

    // Bob decriptează mesajul și trimite lui Alice
    long long C3 = mod_exp(C2, d_B, p);
    std::cout << "C3 (trimis de Bob lui Alice): " << C3 << std::endl;

    // Alice decriptează mesajul
    long long decrypted_message = mod_exp(C3, d_A, p);
    std::cout << "Mesajul decriptat de Alice: " << decrypted_message << std::endl;

    return 0;
}
