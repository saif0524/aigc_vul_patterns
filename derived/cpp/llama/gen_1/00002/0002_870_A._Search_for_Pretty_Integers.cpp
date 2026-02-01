#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (int i = 1; i < 100; ++i) {
        bool hasA = false, hasB = false;
        int num = i;
        while (num > 0) {
            int digit = num % 10;
            if (std::find(a.begin(), a.end(), digit) != a.end()) {
                hasA = true;
            }
            if (std::find(b.begin(), b.end(), digit) != b.end()) {
                hasB = true;
            }
            num /= 10;
        }
        if (hasA && hasB) {
            std::cout << i << std::endl;
            return 0;
        }
    }

    return 0;
}