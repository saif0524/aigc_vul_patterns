#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++) {
        int diff = a[i + 1] - a[i];
        if (diff % (n - 1) == 0) {
            std::cout << a[i] << " " << a[i + 1] << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 2; j < n; j++) {
            int diff = std::abs(a[j] - a[i]);
            if (diff % (n - 1) == 0) {
                std::cout << a[i] << " " << a[j] << std::endl;
                return 0;
            }
        }
    }

    return 0;
}