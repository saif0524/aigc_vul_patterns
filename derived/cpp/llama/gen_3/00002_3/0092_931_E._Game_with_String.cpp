#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int k = n;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool ok = true;
            for (int t = 0; t < n; t++) {
                if (s[(t + i) % n] != s[(t + j) % n]) {
                    ok = false;
                    break;
                }
            }
            dp[i][j] = ok ? 1 : 0;
        }
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> cnt(26, 0);
        for (int j = 0; j < n; j++) {
            int x = s[(j + i) % n] - 'a';
            cnt[x]++;
        }
        for (int c = 0; c < 26; c++) {
            if (cnt[c] == 0) continue;
            vector<int> pos;
            for (int j = 0; j < n; j++) {
                if (s[j] - 'a' == c) pos.push_back(j);
            }
            vector<int> cnt2(n, 0);
            int t = pos[0] - i + n;
            t %= n;
            for (int x : pos) {
                cnt2[(x - t + n) % n]++;
            }
            double mx = -1;
            for (int p = 0; p < n; p++) {
                if (cnt2[p] == 0) continue;
                int bad = 0;
                for (int a = 0; a < n; a++) {
                    if (a == p) continue;
                    if (cnt2[a] > 0 && dp[p][a] == 1) bad++;
                }
                if (bad == 0) {
                    mx = max(mx, (double)cnt2[p]);
                } else {
                    int excit = 0;
                    for (int x = 0; x < n; x++) {
                        if (x != p && dp[p][x] == 1) {
                            excit++;
                        }
                    }
                    mx = max(mx, (double)(cnt2[p] - 1 + excit) / 2.0);
                }
            }
            ans += mx / (double)n;
        }
    }
    printf("%.12f\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}