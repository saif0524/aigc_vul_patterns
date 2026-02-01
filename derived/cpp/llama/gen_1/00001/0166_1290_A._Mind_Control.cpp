#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int solve(int n, int m, int k, std::vector<int>& a) {
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int l = i, r = n - (k - i);
        int mn = INT_MAX;
        for (int j = 0; j <= m - k - 1; j++) {
            mn = std::min(mn, std::max(a[l + j], a[r - (m - k - 1 - j)]));
        }
        ans = std::max(ans, mn);
    }
    return ans;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::cout << solve(n, m, k, a) << std::endl;
    }
    return 0;
}