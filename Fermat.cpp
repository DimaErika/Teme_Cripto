// Exercitiul 3 Tema 4
#include <iostream>
#include <cmath>

// Funcție pentru a verifica dacă un număr este un pătrat perfect
bool is_square(int x) {
    int root = sqrt(x);
    return root * root == x;
}

// Structură pentru a stoca o pereche de factori primi
struct FactorPair {
    int first;
    int second;
};

// Algoritmul de factorizare Fermat
FactorPair fermat_factorization(int n) {
    FactorPair result;

    int a = ceil(sqrt(n));
    int b2 = a * a - n;
    while (!is_square(b2)) {
        ++a;
        b2 = a * a - n;
    }
    int b = sqrt(b2);

    result.first = a - b;
    result.second = a + b;

    return result;
}

int main() {
    int n = 10909;
    FactorPair fermat_factors = fermat_factorization(n);
    std::cout << "Factorii primi ai lui " << n << " folosind algoritmul Fermat sunt: " << fermat_factors.first << " si " << fermat_factors.second << std::endl;

    return 0;
}
