#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << "1 1\n";
        std::cout << -a[0] << "\n";
        std::cout << "1 1\n";
        std::cout << 0 << "\n";
        std::cout << "1 1\n";
        std::cout << 0 << "\n";
        return 0;
    }

    std::cout << "1 1\n";
    std::cout << -a[0] << "\n";
    a[0] = 0;
    std::cout << "2 " << n << "\n";
    for (int i = 1; i < n; ++i) {
        long long x = (n - 1) * ((-a[i]) % n + n);
        a[i] += x;
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "1 " << n << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << -a[i] << " ";
    }
    std::cout << "\n";

    return 0;
}