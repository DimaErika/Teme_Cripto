#include <iostream>
#include <cstdlib>
#include <cmath>

int jacobi_symbol(int a, int n) {
    if (n <= 0 || n % 2 == 0) {
        throw std::invalid_argument("n trebuie să fie un număr întreg pozitiv impar");
    }
    
    // Initializăm simbolul lui Jacobi cu 1
    int symbol = 1;
    
    while (a != 0) {
        while (a % 2 == 0) {
            a /= 2;
            // Regula lui Jacobi pentru a = 2
            if (n % 8 == 3 || n % 8 == 5) {
                symbol *= -1;
            }
        }
        
        // Regula lui Jacobi pentru a și n
        if (a < 0) {
            a = -a;
            if (n % 4 == 3) {
                symbol *= -1;
            }
        }
        
        // Schimbăm a și n folosind legea reciprocității lui Jacobi
        int temp = a;
        a = n;
        n = temp;
        
        // Regula lui Jacobi pentru n
        if (a % 4 == n % 4 && a % 4 == 3) {
            symbol *= -1;
        }
        
        // Reducem a modulo n
        a %= n;
    }
    
    // Dacă n devine 1, returnăm simbolul Jacobi
    if (n == 1) {
        return symbol;
    }
    
    return 0;
}

bool solovay_strassen(int n, int k = 10) {
    if (n == 2) {
        return true;
    }
    if (n <= 1 || n % 2 == 0) {
        return false;
    }

    for (int i = 0; i < k; ++i) {
        int a = rand() % (n - 1) + 1;
        int x = std::pow(a, (n - 1) / 2);
        int j = jacobi_symbol(a, n);
        if (x % n != j % n) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 86813;
    std::cout << "Numărul " << n << " este prim? " << (solovay_strassen(n) ? "Da" : "Nu") << std::endl;
    return 0;
}
