#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int firstPrime(int n) {
    while (true) {
        if (isPrime(n)) return n;
        n++;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int d;
        std::cin >> d;

        int a = firstPrime(d + 1);
        int b = firstPrime(a + d);

        std::cout << a * b << std::endl;
    }

    return 0;
}