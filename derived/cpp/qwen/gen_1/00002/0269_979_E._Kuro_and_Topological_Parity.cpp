#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 50;

int dp[MAXN][2][1 << MAXN];
int n, p;
vector<int> colors;

int solve(int pos, int last_color, int mask) {
    if (pos == n) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask & (1 << i)) && (mask & (1 << j)) && (colors[i] != -1) && (colors[j] != -1) && (colors[i] != colors[j])) {
                    count++;
                }
            }
        }
        return (count % 2 == p);
    }
    int &res = dp[pos][last_color][mask];
    if (res != -1) return res;
    res = 0;
    if (colors[pos] == -1) {
        colors[pos] = 0;
        res = (res + solve(pos + 1, 0, mask | (1 << pos))) % MOD;
        colors[pos] = 1;
        res = (res + solve(pos + 1, 1, mask | (1 << pos))) % MOD;
    } else {
        res = (res + solve(pos + 1, colors[pos], mask | (1 << pos))) % MOD;
    }
    colors[pos] = -1;
    return res;
}

int main() {
    cin >> n >> p;
    colors.resize(n);
    for (auto &c : colors) cin >> c;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 2, 0) << endl;
}