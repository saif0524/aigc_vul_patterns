#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> getDivisors(int n) {
    std::vector<int> divisors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

bool isLosing(int n) {
    std::vector<int> divisors = getDivisors(n);
    if (divisors.empty()) {
        return true;
    }
    for (int divisor : divisors) {
        std::vector<int> subDivisors = getDivisors(divisor);
        if (subDivisors.empty()) {
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    int q;
    std::cin >> q;
    if (isLosing(q)) {
        std::cout << 1 << std::endl;
        std::vector<int> divisors = getDivisors(q);
        if (divisors.empty()) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << divisors[0] << std::endl;
        }
    } else {
        std::cout << 2 << std::endl;
    }
    return 0;
}