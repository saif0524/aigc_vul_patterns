#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
int a[MAXN];
int dp[MAXN][2]; // dp[i][0] : longest non-monotone ending at i going up, dp[i][1] : going down
vector<int> prev_up[MAXN], prev_down[MAXN];

void build(int l, int r) {
    for (int i = l; i <= r; ++i) {
        dp[i][0] = dp[i][1] = 1;
        prev_up[i].clear();
        prev_down[i].clear();
    }
    for (int i = l; i <= r; ++i) {
        for (int j : prev_up[i]) {
            if (a[i] > a[j] && dp[i][0] < dp[j][1] + 1) {
                dp[i][0] = dp[j][1] + 1;
                prev_up[i] = {j};
            } else if (a[i] > a[j] && dp[i][0] == dp[j][1] + 1) {
                prev_up[i].push_back(j);
            }
        }
        for (int j : prev_down[i]) {
            if (a[i] < a[j] && dp[i][1] < dp[j][0] + 1) {
                dp[i][1] = dp[j][0] + 1;
                prev_down[i] = {j};
            } else if (a[i] < a[j] && dp[i][1] == dp[j][0] + 1) {
                prev_down[i].push_back(j);
            }
        }
        if (a[i] == a[i - 1]) continue;
        if (a[i] > a[i - 1]) {
            if (dp[i][0] < dp[i - 1][1] + 1) {
                dp[i][0] = dp[i - 1][1] + 1;
                prev_up[i] = {i - 1};
            } else if (dp[i][0] == dp[i - 1][1] + 1) {
                prev_up[i].push_back(i - 1);
            }
        } else {
            if (dp[i][1] < dp[i - 1][0] + 1) {
                dp[i][1] = dp[i - 1][0] + 1;
                prev_down[i] = {i - 1};
            } else if (dp[i][1] == dp[i - 1][0] + 1) {
                prev_down[i].push_back(i - 1);
            }
        }
    }
}

void backtrack(int i, int dir, vector<int>& path) {
    if (i == 0) return;
    path.push_back(i);
    if (dir == 0) {
        for (int j : prev_up[i]) {
            backtrack(j, 1, path);
        }
    } else {
        for (int j : prev_down[i]) {
            backtrack(j, 0, path);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    while(q--){
        int L, R;
        cin >> L >> R;
        if(R - L < 2){
            cout << "0\n";
            continue;
        }
        build(L, R);
        int max_len = 0;
        int end_idx = 0;
        int end_dir = 0;
        for(int i=R;i>=L;i--){
            if(dp[i][0] > max_len){
                max_len = dp[i][0];
                end_idx = i;
                end_dir = 0;
            }
            if(dp[i][1] > max_len){
                max_len = dp[i][1];
                end_idx = i;
                end_dir = 1;
            }
        }
        if(max_len <= 2){
            cout << "0\n";
            continue;
        }
        vector<int> path;
        backtrack(end_idx, end_dir, path);
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for(int x : path) cout << x << " ";
        cout << "\n";
    }
}