#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    int count = 0;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++count;
            n /= i;
        }
    }
    if (n > 1) {
        ++count;
    }
    std::cout << count;
}