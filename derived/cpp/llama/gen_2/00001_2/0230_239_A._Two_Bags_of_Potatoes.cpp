#include <iostream>

int main() {
    long long y, k, n;
    std::cin >> y >> k >> n;

    bool found = false;
    for (long long x = 0; x <= n - y; x++) {
        if ((x + y) % k == 0) {
            if (!found) found = true;
            std::cout << x << " ";
        }
    }

    if (!found) std::cout << -1;
    return 0;
}