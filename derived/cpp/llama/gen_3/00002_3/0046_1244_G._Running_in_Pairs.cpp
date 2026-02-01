#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        q[i] = n - i;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::max(p[i], q[i]);
    }

    if (sum > k) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << sum << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << q[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}