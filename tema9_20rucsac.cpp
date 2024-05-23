#include <iostream>
#include <vector>

std::vector<int> generate_superincreasing_sequence(int k) {
    std::vector<int> sequence(k);
    sequence[0] = 1;
    for (int i = 1; i < k; i++) {
        sequence[i] = sequence[i - 1] + rand() % 10 + 1; // Generare supercrescătoare
    }
    return sequence;
}

std::vector<int> solve_knapsack(const std::vector<int> &sequence, int V) {
    int n = sequence.size();
    std::vector<int> solution(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (V >= sequence[i]) {
            solution[i] = 1;
            V -= sequence[i];
        }
    }
    return solution;
}

int main() {
    int k;
    std::cout << "Introduceți numărul k: ";
    std::cin >> k;

    std::vector<int> superincreasing_sequence = generate_superincreasing_sequence(k);
    std::cout << "Șirul supercrescător generat: ";
    for (auto num : superincreasing_sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int V = 473;
    std::vector<int> solution = solve_knapsack(superincreasing_sequence, V);
    std::cout << "Soluția problemei rucsacului pentru V = " << V << ": ";
    for (auto bit : solution) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    return 0;
}
