#include <iostream>
#include <cmath>

std::pair<long long, long long> f(long long x) {
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            long long j = x / i;
            return {i, j};
        }
    }
    return {x, 1};
}

int main() {
    long long x;
    std::cin >> x;
    auto [a, b] = f(x);
    std::cout << a << " " << b << std::endl;
    return 0;
}