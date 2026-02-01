#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n, q, k, d;
    std::cin >> n >> q >> k >> d;

    std::vector<int> ans;
    while (q--) {
        if (k <= n / 2) {
            if (d <= n / 2) {
                ans.push_back(0);
                d--;
                k--;
            } else {
                ans.push_back(1);
                d = n - d + 1;
            }
        } else {
            if (d <= n / 2) {
                ans.push_back(1);
                d = n / 2 - d + 1;
                k = n / 2 - (k - n / 2);
            } else {
                ans.push_back(0);
                d = n - d + 1;
                k = n / 2 - (k - n / 2);
            }
        }
        n /= 2;
    }

    if (k != d) {
        std::cout << -1 << std::endl;
    } else {
        for (int i = ans.size() - 1; i >= 0; i--) {
            std::cout << ans[i] << std::endl;
        }
    }

    return 0;
}