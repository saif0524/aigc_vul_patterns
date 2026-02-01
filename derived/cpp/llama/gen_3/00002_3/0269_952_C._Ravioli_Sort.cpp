#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1] && a[j] - a[j + 1] > 1) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "YES" << std::endl;
    return 0;
}