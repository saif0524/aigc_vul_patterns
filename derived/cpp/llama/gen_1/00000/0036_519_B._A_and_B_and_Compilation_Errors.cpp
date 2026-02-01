#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n - 1), c(n - 2);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < n - 2; ++i) {
        std::cin >> c[i];
    }

    std::vector<int> d;
    for (int i = 0; i < n; ++i) {
        if (std::find(b.begin(), b.end(), a[i]) == b.end()) {
            d.push_back(a[i]);
        }
    }

    std::vector<int> e;
    for (int i = 0; i < n - 1; ++i) {
        if (std::find(c.begin(), c.end(), b[i]) == c.end()) {
            e.push_back(b[i]);
        }
    }

    for (int i = 0; i < d.size(); ++i) {
        std::cout << d[i] << " ";
    }

    for (int i = 0; i < e.size(); ++i) {
        std::cout << e[i] << " ";
    }

    return 0;
}