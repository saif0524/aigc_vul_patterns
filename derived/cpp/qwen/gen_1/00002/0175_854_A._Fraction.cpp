#include <iostream>
#include <algorithm>
#include <cstdlib>

bool areCoprime(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a == 1;
}

int main() {
    int n;
    std::cin >> n;
    int a = 1, b = n - 1;

    for (int i = 1; i < n; ++i) {
        if (areCoprime(i, n - i) && i > a) {
            a = i;
            b = n - i;
        }
    }

    std::cout << a << " " << b << std::endl;
    return 0;
}