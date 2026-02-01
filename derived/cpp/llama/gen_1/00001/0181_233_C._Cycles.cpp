#include <iostream>
#include <vector>
#include <string>

int main() {
    int k;
    std::cin >> k;

    int n = 3;
    while (true) {
        int m = (n * (n - 1) * (n - 2)) / 6;
        if (m > k) {
            break;
        }
        n++;
    }
    n--;

    std::vector<std::vector<bool>> graph(n, std::vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            graph[i][j] = true;
            graph[j][i] = true;
        }
    }

    int remaining = k - (n * (n - 1) * (n - 2)) / 6;

    int additional = 0;
    for (int i = 3; i < 100; i++) {
        int newNode = (i * (i - 1)) / 2;
        if (newNode > remaining) {
            break;
        }
        additional = i;
        remaining -= newNode;
    }

    if (additional > 0) {
        for (int i = 0; i < additional; i++) {
            for (int j = 0; j < n; j++) {
                graph[n][j] = true;
                graph[j][n] = true;
            }
            n++;
        }
    }

    std::cout << n << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                std::cout << "1";
            } else {
                std::cout << "0";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}