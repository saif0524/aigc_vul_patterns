#include <iostream>
#include <vector>
#include <map>

const int MOD = 998244353;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        std::map<int, int> count;
        int sum = 0;
        for (int j = i; j > 0; j--) {
            count[a[j - 1]]++;
            int cnt = 0;
            for (auto& [key, value] : count) {
                if (value == 1) {
                    cnt++;
                }
            }
            if (cnt <= k) {
                sum = (sum + dp[j - 1]) % MOD;
            }
        }
        dp[i] = sum;
    }

    std::cout << dp[n] << std::endl;

    return 0;
}