#include <iostream>

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) break;

        int a[n];
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int exchanges = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    exchanges++;
                }
            }
        }

        std::cout << exchanges << std::endl;
    }

    return 0;
}