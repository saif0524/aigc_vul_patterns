#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int d;
        std::cin >> d;
        int p1 = 1 + d;
        while (!isPrime(p1)) p1++;
        int p2 = p1 + d;
        while (!isPrime(p2)) p2++;
        std::cout << p1 * p2 << std::endl;
    }
    return 0;
}