#include <iostream>
#include <vector>
#include <string>

int main() {
    int k;
    std::cin >> k;

    int n = 3;
    while (true) {
        int cycles = (n * (n - 1) * (n - 2)) / 6;
        if (cycles >= k) {
            break;
        }
        n++;
    }

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            graph[i][j] = 1;
            graph[j][i] = 1;
        }
    }

    int remove = (n * (n - 1) * (n - 2)) / 6 - k;
    int removed = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (removed < remove) {
                graph[i][j] = 0;
                graph[j][i] = 0;
                removed++;
            }
        }
    }

    std::cout << n << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << graph[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}