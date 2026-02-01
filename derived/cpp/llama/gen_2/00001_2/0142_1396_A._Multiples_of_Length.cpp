#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << "1 1\n";
    std::cout << -a[0] << "\n";

    if (n == 1) {
        std::cout << "1 1\n";
        std::cout << "0\n";
        std::cout << "1 1\n";
        std::cout << "0\n";
    } else {
        std::cout << "2 " << n << "\n";
        for (int i = 1; i < n; i++) {
            std::cout << -(n - 1) * a[i] << " ";
        }
        std::cout << "\n";
        std::cout << "1 " << n << "\n";
        std::cout << 0 << " ";
        for (int i = 1; i < n; i++) {
            std::cout << n * a[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}