#include <iostream>
#include <cmath>

bool isPrime(long long num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        long long num;
        std::cin >> num;
        if (isPrime(num)) count++;
    }
    std::cout << count << std::endl;
    return 0;
}