#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

const int MOD = 1e9 + 7;

int countWaysToSeparate(const std::string& t, const std::vector<std::string>& S) {
    int n = t.size();
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (const std::string& s : S) {
            int len = s.size();
            if (i >= len && t.substr(i - len, len) == s) {
                dp[i] = (dp[i] + dp[i - len]) % MOD;
            }
        }
    }
    return dp[n];
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
    }
    std::string t;
    std::cin >> t;
    int result = countWaysToSeparate(t, S);
    std::cout << result << std::endl;
    return 0;
}