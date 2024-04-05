#include <iostream>
#include <vector>
#include <cmath>

// Funcție pentru a verifica dacă un număr este prim
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Funcție pentru a genera un set de numere prime în intervalul [1, B]
std::vector<int> generate_primes(int B) {
    std::vector<int> primes;
    for (int i = 2; i <= B; ++i) {
        if (is_prime(i)) primes.push_back(i);
    }
    return primes;
}

// Funcție pentru a calcula valori x^2 mod n pentru fiecare x din intervalul [1, B]
std::vector<int> calculate_squares_mod_n(int n, int B) {
    std::vector<int> squares_mod_n;
    for (int x = 1; x <= B; ++x) {
        int square_mod_n = (x * x) % n;
        squares_mod_n.push_back(square_mod_n);
    }
    return squares_mod_n;
}

// Funcție pentru criblarea spațiului
void sieve_space(int n, const std::vector<int>& primes, const std::vector<int>& squares_mod_n) {
    // Initializează o matrice M cu dimensiunea numărului de numere prime
    int k = primes.size();
    std::vector<std::vector<int>> M(k, std::vector<int>(k, 0));

    // Pentru fiecare număr x în intervalul [1, B], determină factorizarea în numere prime și actualizează matricea M
    for (int i = 0; i < squares_mod_n.size(); ++i) {
        int x_squared_mod_n = squares_mod_n[i];
        for (int j = 0; j < k; ++j) {
            int p = primes[j];
            while (x_squared_mod_n % p == 0) {
                ++M[j][i];
                x_squared_mod_n /= p;
            }
        }
    }

    // Identifică numerele B-smooth și construiește o listă de perechi (x, y) corespunzătoare lor
    std::vector<std::pair<int, std::vector<int>>> smooth_numbers;
    for (int i = 0; i < squares_mod_n.size(); ++i) {
        bool is_smooth = true;
        std::vector<int> factors;
        for (int j = 0; j < k; ++j) {
            if (M[j][i] % 2 != 0) {
                is_smooth = false;
                break;
            }
            factors.push_back(M[j][i] / 2);
        }
        if (is_smooth) {
            smooth_numbers.push_back(std::make_pair(i + 1, factors));
        }
    }

    // Afiseaza numerele B-smooth si factorii lor asociati
    std::cout << "Numerele B-smooth si factorii lor asociati sunt:" << std::endl;
    for (const auto& number : smooth_numbers) {
        std::cout << "Numar: " << number.first << ", Factori: ";
        for (int factor : number.second) {
            std::cout << factor << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 10909; // Numărul de factorizat
    int B = 100; // Limita superioară pentru generarea numerelor prime și calculul pătratelor mod n

    // Generăm numere prime în intervalul [1, B]
    std::vector<int> primes = generate_primes(B);

    // Calculăm valorile pătratelor mod n pentru fiecare x în intervalul [1, B]
    std::vector<int> squares_mod_n = calculate_squares_mod_n(n, B);

    // Criblăm spațiul pentru a găsi numerele B-smooth
    sieve_space(n, primes, squares_mod_n);

    return 0;
}
