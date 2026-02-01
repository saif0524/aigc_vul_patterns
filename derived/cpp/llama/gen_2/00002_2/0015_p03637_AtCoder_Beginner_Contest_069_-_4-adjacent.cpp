#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int countEven = 0, countMultipleOf4 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            countEven++;
            if (a[i] % 4 == 0) {
                countMultipleOf4++;
            }
        }
    }

    if (countEven == 0) {
        std::cout << "No" << std::endl;
    } else if (countMultipleOf4 == 0 && countEven == 1) {
        std::cout << "No" << std::endl;
    } else if (countMultipleOf4 == 0 && countEven == 2 && n == 2) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}