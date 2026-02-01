#include <iostream>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int l, r, d;
        std::cin >> l >> r >> d;

        int x = (r / d + 1) * d;
        std::cout << x << std::endl;
    }

    return 0;
}