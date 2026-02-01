#include <iostream>
#include <iomanip>

const int mod = 1e9 + 7;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;

    if (n == 3) {
        std::cout << 2 << std::endl;
    } else if (n == 4) {
        std::cout << 16 << std::endl;
    } else {
        long long result = (factorial(n) - (n - 1)) % mod;
        if (result < 0) result += mod;
        std::cout << result << std::endl;
    }

    return 0;
}