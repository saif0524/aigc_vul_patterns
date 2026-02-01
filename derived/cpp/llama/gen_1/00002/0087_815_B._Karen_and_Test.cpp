#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int sign = 1;
    while (a.size() > 1) {
        std::vector<int> b;
        for (int i = 0; i < a.size() - 1; i++) {
            int x = (a[i] + sign * a[i + 1]) % MOD;
            b.push_back(x);
        }
        sign *= -1;
        a = b;
    }

    std::cout << (a[0] + MOD) % MOD << std::endl;

    return 0;
}