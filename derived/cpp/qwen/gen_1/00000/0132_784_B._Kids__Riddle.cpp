#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    int count = 0;
    for (long long i = 2; i <= std::sqrt(n); ++i) {
        while (n % i == 0) {
            n /= i;
            ++count;
            if (n % i != 0) break;
        }
    }
    if (n > 1) ++count;
    std::cout << count;
    return 0;
}