#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> cnta(6, 0), cntb(6, 0);
    for (int i = 0; i < n; i++) {
        cnta[a[i]]++;
        cntb[b[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= 5; i++) {
        if ((cnta[i] + cntb[i]) % 2!= 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        ans += std::abs(cnta[i] - cntb[i]) / 2;
    }

    std::cout << ans << std::endl;

    return 0;
}