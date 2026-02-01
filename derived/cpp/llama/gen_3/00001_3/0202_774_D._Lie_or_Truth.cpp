#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    --l; --r;

    for (int i = 0; i < l; ++i) {
        if (a[i]!= b[i]) {
            std::cout << "LIE" << std::endl;
            return 0;
        }
    }

    for (int i = r + 1; i < n; ++i) {
        if (a[i]!= b[i]) {
            std::cout << "LIE" << std::endl;
            return 0;
        }
    }

    std::vector<int> a_sub(a.begin() + l, a.begin() + r + 1);
    std::vector<int> b_sub(b.begin() + l, b.begin() + r + 1);

    std::sort(a_sub.begin(), a_sub.end());
    std::sort(b_sub.begin(), b_sub.end());

    if (a_sub == b_sub) {
        std::cout << "TRUTH" << std::endl;
    } else {
        std::cout << "LIE" << std::endl;
    }

    return 0;
}