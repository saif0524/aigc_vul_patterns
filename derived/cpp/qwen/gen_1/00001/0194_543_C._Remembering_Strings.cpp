#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25, MAXM = 25, MAXC = 26;
const long long INF = 1e18;

int n, m;
string s[MAXN];
int cost[MAXN][MAXM];
long long dp[1 << (MAXM * MAXC)];

int get_char(int mask, int pos) {
    for (int i = 0; i < MAXC; ++i) {
        if (mask & (1 << (i * MAXM + pos))) return i;
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cost[i][j];
        }
    }
    
    int full_mask = (1 << (m * MAXC)) - 1;
    for (int mask = 0; mask <= full_mask; ++mask) dp[mask] = INF;
    dp[0] = 0;
    
    for (int mask = 0; mask <= full_mask; ++mask) {
        for (int i = 0; i < n; ++i) {
            int new_mask = mask;
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                int c = s[i][j] - 'a';
                if (new_mask & (1 << (c * MAXM + j))) {
                    valid = false;
                    break;
                }
                new_mask |= (1 << (c * MAXM + j));
                for (int k = 0; k < MAXC; ++k) {
                    if (k != c && (new_mask & (1 << (k * MAXM + j)))) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) continue;
            long long new_cost = dp[mask];
            for (int j = 0; j < m; ++j) {
                int c = get_char(new_mask, j);
                if (c != s[i][j] - 'a') {
                    new_cost += cost[i][j];
                }
            }
            dp[new_mask] = min(dp[new_mask], new_cost);
        }
    }
    
    cout << dp[full_mask] << "\n";
    return 0;
}