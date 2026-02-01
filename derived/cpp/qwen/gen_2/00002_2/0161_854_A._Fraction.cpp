#include <iostream>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    int a = 1, b = n - 1;
    for (int i = 1; i <= n / 2; ++i) {
        int j = n - i;
        if (std::gcd(i, j) == 1 && i < j) {
            a = i;
            b = j;
        }
    }
    std::cout << a << " " << b << std::endl;
    return 0;
}