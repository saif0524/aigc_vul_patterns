#include <iostream>

int main() {
    int n, m, z;
    std::cin >> n >> m >> z;

    int count = 0;
    for (int i = 1; i <= z; i++) {
        if (i % n == 0 && i % m == 0) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}