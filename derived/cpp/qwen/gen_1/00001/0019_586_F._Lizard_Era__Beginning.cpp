#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 25;
const int INF = 1e9;

int n;
int a[MAXN][3];
int dp[1<<14][3];
pair<int, int> path[1<<14][3];

void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int mask = 0; mask < (1<<n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < 3; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        if (j != k) {
                            int nmask = mask ^ (1 << i);
                            int v = dp[nmask][j] + a[i][j] + a[i][k];
                            if (dp[mask][k] < v) {
                                dp[mask][k] = v;
                                path[mask][k] = {j, i};
                            }
                        }
                    }
                }
            }
        }
    }
    int best = -INF, idx = -1;
    for (int i = 0; i < 3; ++i) {
        if (dp[(1<<n)-1][i] > best && dp[(1<<n)-1][i] == dp[(1<<n)-1][(i+1)%3] && dp[(1<<n)-1][i] == dp[(1<<n)-1][(i+2)%3]) {
            best = dp[(1<<n)-1][i];
            idx = i;
        }
    }
    if (idx == -1) {
        cout << "Impossible";
        return;
    }
    vector<string> ans;
    int mask = (1<<n) - 1;
    for (int i = 0; i < n; ++i) {
        auto [j, k] = path[mask][idx];
        string s;
        if (j == 0) s += 'L';
        else if (j == 1) s += 'M';
        else s += 'W';
        if (idx == 0) s += 'L';
        else if (idx == 1) s += 'M';
        else s += 'W';
        sort(s.begin(), s.end());
        ans.push_back(s);
        mask ^= (1 << k);
        idx = j;
    }
    reverse(ans.begin(), ans.end());
    for (auto &s : ans) {
        cout << s << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    solve();
}