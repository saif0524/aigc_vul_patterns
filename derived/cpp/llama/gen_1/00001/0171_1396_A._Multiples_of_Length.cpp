#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << 1 << " " << 1 << std::endl;
    std::cout << -a[0] << std::endl;

    if (n == 1) {
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << 0 << std::endl;
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << 0 << std::endl;
    } else {
        std::cout << 2 << " " << n << std::endl;
        for (int i = 1; i < n; i++) {
            std::cout << -a[i] * (n - 1) << " ";
        }
        std::cout << std::endl;

        std::cout << 1 << " " << n << std::endl;
        std::cout << 0 << " ";
        for (int i = 1; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}