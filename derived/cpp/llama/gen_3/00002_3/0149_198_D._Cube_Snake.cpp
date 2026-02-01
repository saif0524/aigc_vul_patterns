#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    int num = 1;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << num++ << " ";
            }
            std::cout << "\n";
        }
        if (k < n - 1) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    std::cout << num++ << " ";
                }
                std::cout << "\n";
            }
        }
    }
    return 0;
}