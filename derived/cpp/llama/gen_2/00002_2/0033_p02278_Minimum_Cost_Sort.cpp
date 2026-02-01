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

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    int cost = 0;
    for (int i = 0; i < n; i++) {
        if (p[i]!= i) {
            int j = p[i];
            while (j!= i) {
                cost += w[i] + w[j];
                std::swap(p[i], p[j]);
                j = p[i];
            }
            cost += w[i] + w[j];
        }
    }

    std::cout << cost << std::endl;

    return 0;
}