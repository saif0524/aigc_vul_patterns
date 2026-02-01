#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    if (std::equal(a.begin(), a.begin() + l - 1, b.begin()) && 
        std::equal(a.begin() + r, a.end(), b.begin() + r)) {
        std::cout << "TRUTH" << std::endl;
    } else {
        std::cout << "LIE" << std::endl;
    }

    return 0;
}