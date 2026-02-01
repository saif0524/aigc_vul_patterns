#include <bits/stdc++.h>
using namespace std;

int x, y;
vector<pair<int, char>> connections[8];
string initial[4], target[4];
int dp[1 << 10][4][4];

int getMask(const string &s) {
    int mask = 0;
    for (char c : s) {
        mask |= (1 << (c - 'a'));
    }
    return mask;
}

bool canForm(int mask, const string &s) {
    int req = getMask(s);
    return (mask & req) == req;
}

int dfs(int mask, int a, int b) {
    if (mask == 0) return 0;
    if (dp[mask][a][b] != -1) return dp[mask][a][b];
    int res = 1e9;
    for (int i = 0; i < x; ++i) {
        if (canForm(mask, initial[i])) {
            int newMask = mask ^ getMask(initial[i]);
            res = min(res, 1 + dfs(newMask, i, b));
        }
        if (canForm(mask, target[i])) {
            int newMask = mask ^ getMask(target[i]);
            res = min(res, 1 + dfs(newMask, a, i));
        }
    }
    for (auto &[line, dir] : connections[a]) {
        if (dir == 'W') {
            for (int i = 0; i <= initial[line].size(); ++i) {
                string prefix = initial[line].substr(0, i);
                if (canForm(mask, prefix)) {
                    int newMask = mask ^ getMask(prefix);
                    int suffixMask = getMask(initial[line].substr(i));
                    for (auto &[targetLine, targetDir] : connections[line]) {
                        if (targetDir == 'E' && canForm(suffixMask, target[targetLine])) {
                            int finalMask = newMask ^ getMask(target[targetLine]);
                            res = min(res, 2 + dfs(finalMask, a, targetLine));
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i <= initial[line].size(); ++i) {
                string suffix = initial[line].substr(i);
                if (canForm(mask, suffix)) {
                    int newMask = mask ^ getMask(suffix);
                    int prefixMask = getMask(initial[line].substr(0, i));
                    for (auto &[targetLine, targetDir] : connections[line]) {
                        if (targetDir == 'W' && canForm(prefixMask, target[targetLine])) {
                            int finalMask = newMask ^ getMask(target[targetLine]);
                            res = min(res, 2 + dfs(finalMask, a, targetLine));
                        }
                    }
                }
            }
        }
    }
    return dp[mask][a][b] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;
        for (int i = 0; i < 8; ++i) connections[i].clear();
        for (int i = 0; i < (1 << 10); ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        for (int i = 0; i < y; ++i) {
            int p, q;
            char P, Q;
            cin >> p >> P >> q >> Q;
            connections[p].emplace_back(q, Q);
            connections[q].emplace_back(p, P);
        }
        for (int i = 0; i < x; ++i) cin >> initial[i];
        for (int i = 0; i < x; ++i) cin >> target[i];
        int fullMask = 0;
        for (int i = 0; i < x; ++i) {
            fullMask |= getMask(initial[i]);
        }
        cout << dfs(fullMask, 0, 0) << "\n";
    }
}