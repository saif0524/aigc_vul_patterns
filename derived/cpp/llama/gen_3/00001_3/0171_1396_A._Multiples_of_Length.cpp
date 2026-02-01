#include <iostream>

int main() {
    int n;
    std::cin >> n;

    long long* a = new long long[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << -a[0] << std::endl;
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << 0 << std::endl;
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << " " << 1 << std::endl;
        std::cout << -a[0] << std::endl;
        std::cout << 2 << " " << n << std::endl;
        for (int i = 1; i < n; i++) {
            std::cout << a[i] * (n - 1) << " ";
            a[i] += a[i] * (n - 1);
        }
        std::cout << std::endl;
        std::cout << 1 << " " << n << std::endl;
        std::cout << 0 << " ";
        for (int i = 1; i < n; i++) {
            std::cout << -a[i] << " ";
        }
        std::cout << std::endl;
    }

    delete[] a;
    return 0;
}