#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, n;
        std::cin >> a >> b >> n;

        std::vector<int> f(n + 1);
        f[0] = a;
        if (n > 0) f[1] = b;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i-1] ^ f[i-2];
        }

        std::cout << f[n] << std::endl;
    }

    return 0;
}