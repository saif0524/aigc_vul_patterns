#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int N = 5000 + 5;
const int MOD = 1e9 + 7;

char s[N];
int dp[N][N][27];
int sum[N][27];
int nxt[N];
int pre[N];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 25; ++j) sum[i][j] = sum[i - 1][j];
        sum[i][s[i] - 'a']++;
    }
    for (int i = 1; i <= n; ++i) {
        nxt[i] = i;
        pre[i] = i;
        for (int j = i - 1; j >= 1; --j) {
            if (s[j] == s[i]) nxt[j] = nxt[i];
            else break;
        }
        for (int j = i + 1; j <= n; ++j) {
            if (s[j] == s[i]) pre[j] = pre[i];
            else break;
        }
    }
    for (int i = 1; i <= n; ++i) dp[i][i][s[i] - 'a'] = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = i; j <= n; ++j) {
            for (int k = 0; k <= 25; ++k) {
                if (i == j) {
                    dp[i][j][k] = (dp[i][j][k] + sum[j][k] - sum[i - 1][k]) % MOD;
                } else {
                    if (k != s[i] - 'a' && nxt[i] <= j) {
                        dp[i][j][k] = (dp[i][j][k] + dp[nxt[i]][j][k]) % MOD;
                    }
                    if (k != s[j] - 'a' && pre[j] >= i) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i][pre[j] - 1][k]) % MOD;
                    }
                }
            }
            if (i == j) continue;
            dp[i][j][s[i] - 'a'] = (dp[i][j][s[i] - 'a'] + dp[i + 1][j][s[i] - 'a']) % MOD;
            dp[i][j][s[j] - 'a'] = (dp[i][j][s[j] - 'a'] + dp[i][j - 1][s[j] - 'a']) % MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 25; ++i) ans = (ans + dp[1][n][i]) % MOD;
    printf("%d\n", ans);
    return 0;
}