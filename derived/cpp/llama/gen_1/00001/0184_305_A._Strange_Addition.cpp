#include <bits/stdc++.h>
using namespace std;

bool canSum(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    int maxLen = max(s1.length(), s2.length());
    s1 = string(maxLen - s1.length(), '0') + s1;
    s2 = string(maxLen - s2.length(), '0') + s2;
    for (int i = 0; i < maxLen; i++) {
        if (s1[i] != '0' && s2[i] != '0') return false;
    }
    return true;
}

void solve() {
    int k;
    cin >> k;
    vector<int> d(k);
    for (int& x : d) cin >> x;
    int n = d.size();
    vector<vector<bool>> dp(n, vector<bool>(n, true));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && !canSum(d[i], d[j])) {
                dp[i][j] = false;
            }
        }
    }
    vector<bool> vis(n, false);
    int ans = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<bool> currVis(n, false);
        int currAns = 0;
        queue<int> q;
        q.push(i);
        currVis[i] = true;
        currAns++;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int j = 0; j < n; j++) {
                if (!currVis[j] && dp[x][j]) {
                    currVis[j] = true;
                    q.push(j);
                    currAns++;
                }
            }
        }
        if (currAns > ans) {
            ans = currAns;
            start = i;
        }
    }
    cout << ans << endl;
    vector<bool> currVis(n, false);
    queue<int> q;
    q.push(start);
    currVis[start] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        cout << d[x] << " ";
        for (int j = 0; j < n; j++) {
            if (!currVis[j] && dp[x][j]) {
                currVis[j] = true;
                q.push(j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}