#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.size();
    int m = t.size();

    std::vector<int> pref(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pref[i - 1];
        while (j > 0 && t[i] != t[j]) j = pref[j - 1];
        if (t[i] == t[j]) j++;
        pref[i] = j;
    }

    int ans = 0;
    std::vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            for (int j = 0; j < m; j++) {
                if (t[j] == s[i] || s[i] == '?') {
                    int cnt = 0;
                    int k = i;
                    while (k >= 0 && k - i + 1 <= m && (s[k] == '?' || s[k] == t[j])) {
                        if (s[k] != '?') cnt++;
                        k--;
                        j++;
                        if (j == m) {
                            ans = std::max(ans, cnt + dp[k + 1] + 1);
                            j = pref[j - 1];
                        }
                    }
                    dp[i + 1] = std::max(dp[i + 1], cnt + dp[k + 1]);
                }
            }
        } else {
            int cnt = 0;
            int k = i;
            int j = 0;
            while (k >= 0 && k - i + 1 <= m && (s[k] == t[j])) {
                cnt++;
                k--;
                j++;
                if (j == m) {
                    ans = std::max(ans, cnt + dp[k + 1] + 1);
                    j = pref[j - 1];
                }
            }
            dp[i + 1] = std::max(dp[i + 1], cnt + dp[k + 1]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}