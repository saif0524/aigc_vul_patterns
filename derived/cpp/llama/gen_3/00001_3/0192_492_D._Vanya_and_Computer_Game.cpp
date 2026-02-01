#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        double t1 = (a[i] - 1) / static_cast<double>(x) + 1.0 / x;
        double t2 = (a[i] - 1) / static_cast<double>(y) + 1.0 / y;

        if (t1 < t2) {
            std::cout << "Vanya" << std::endl;
        } else if (t1 > t2) {
            std::cout << "Vova" << std::endl;
        } else {
            std::cout << "Both" << std::endl;
        }
    }

    return 0;
}