#include <iostream>
#include <string>
#include <vector>

const long long mod = 1e9 + 7;

int n;
std::string s;
std::vector<int> dp[77][77][77];

long long rec(int i, int j, int k) {
    if (k == 0) return 1;
    if (i + k - 1 > n) return 0;
    if (dp[i][j][k].size() > 0) return dp[i][j][k][0];

    long long ans = 0;
    for (int l = i + 1; l <= n - k + 2; l++) {
        int p = 0;
        for (int m = i; m < l; m++) {
            p = p * 2 + (s[m] - '0');
        }
        if (p == j) {
            ans += rec(l, 1, k - 1);
        } else if (p > j && p <= j + k - 1) {
            ans += rec(l, p, k - 1);
        }
    }

    ans %= mod;
    dp[i][j][k].push_back(ans);
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> s;

    long long ans = 0;
    for (int i = 1; i <= 75; i++) {
        ans += rec(0, 0, i);
        ans %= mod;
    }

    std::cout << ans << "\n";

    return 0;
}