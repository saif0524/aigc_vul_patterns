#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    std::vector<int> sorted_w = w;
    std::sort(sorted_w.begin(), sorted_w.end());

    int cost = 0;
    for (int i = 0; i < n; i++) {
        while (w[i] != sorted_w[i]) {
            for (int j = i + 1; j < n; j++) {
                if (w[j] == sorted_w[i]) {
                    cost += w[i] + w[j];
                    std::swap(w[i], w[j]);
                    break;
                }
            }
        }
    }

    std::cout << cost << std::endl;

    return 0;
}