#include <iostream>

// Exercitiul 5 


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

int main() {
    int a = 10;
    int n = 21;
    std::cout << "Simbolul lui Jacobi între " << a << " și " << n << " este: " << jacobi_symbol(a, n) << std::endl;
    return 0;
}
