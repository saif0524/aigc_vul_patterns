#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

std::vector<long long> getDivisors(long long n) {
    std::vector<long long> divisors;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) divisors.push_back(n / i);
        }
    }
    return divisors;
}

int main() {
    long long q;
    std::cin >> q;

    if (isPrime(q)) {
        std::cout << "1\n0\n";
    } else {
        std::vector<long long> divisors = getDivisors(q);
        int count = 0;
        for (long long divisor : divisors) {
            if (isPrime(divisor)) count++;
        }
        if (count == 2) {
            std::cout << "2\n";
        } else {
            std::cout << "1\n";
            bool found = false;
            for (long long divisor : divisors) {
                std::vector<long long> subDivisors = getDivisors(divisor);
                int subCount = 0;
                for (long long subDivisor : subDivisors) {
                    if (isPrime(subDivisor)) subCount++;
                }
                if (subCount == 2) {
                    std::cout << divisor << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "0\n";
        }
    }

    return 0;
}