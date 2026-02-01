#include <iostream>
#include <vector>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int a, b, n;
        std::cin >> a >> b >> n;
        if (n == 0) {
            std::cout << a << std::endl;
        } else if (n == 1) {
            std::cout << b << std::endl;
        } else {
            std::vector<int> xorinacci(3);
            xorinacci[0] = a;
            xorinacci[1] = b;
            xorinacci[2] = a ^ b;
            n = n % 6; // XORinacci sequence repeats every 6 numbers
            std::cout << xorinacci[n] << std::endl;
        }
    }
    return 0;
}