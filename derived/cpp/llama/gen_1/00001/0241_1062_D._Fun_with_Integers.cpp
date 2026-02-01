#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            ans += i;
            ans += n / i;
        }
    }

    std::cout << ans - (n / 2) * 2 << std::endl;

    return 0;
}