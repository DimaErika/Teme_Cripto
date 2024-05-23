#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int value;
    int weight;
};

int knapsack(int W, std::vector<Item> &items, int n) {
    std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                K[i][w] = std::max(items[i - 1].value + K[i - 1][w - items[i - 1].weight], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    return K[n][W];
}

int main() {
    int W;
    std::cout << "Introduceți capacitatea rucsacului: ";
    std::cin >> W;

    int n;
    std::cout << "Introduceți numărul de obiecte: ";
    std::cin >> n;

    std::vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Introduceți valoarea și greutatea pentru obiectul " << i + 1 << ": ";
        std::cin >> items[i].value >> items[i].weight;
    }

    int max_value = knapsack(W, items, n);
    std::cout << "Valoarea maximă care poate fi obținută: " << max_value << std::endl;

    return 0;
}
