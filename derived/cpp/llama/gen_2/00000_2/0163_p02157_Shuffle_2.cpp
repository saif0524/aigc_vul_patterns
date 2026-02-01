#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    long long n, q, k, d;
    std::cin >> n >> q >> k >> d;

    std::vector<int> ans;
    k -= 1;
    d -= 1;

    for (int i = 0; i < q; i++) {
        if (k % 2 == d % 2) {
            ans.push_back(0);
            if (k % 2 == 1) {
                k = k / 2;
                d = d / 2;
            } else {
                k = k / 2 - n / 2;
                d = d / 2 - n / 2;
            }
        } else {
            ans.push_back(1);
            if (k % 2 == 0) {
                k = k / 2 + n / 2;
                d = d / 2;
            } else {
                k = k / 2;
                d = d / 2 + n / 2;
            }
        }
        n = n / 2;
    }
    if (k == d) {
        for (auto it = ans.rbegin(); it != ans.rend(); it++) {
            std::cout << *it << "\n";
        }
    } else {
        std::cout << "-1\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}