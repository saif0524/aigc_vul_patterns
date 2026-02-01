#include <bits/stdc++.h>
using namespace std;

long long dp[3501][3501][2];

long long solve(int l, int r, bool f, int n, int m, int k, const vector<int>& a, int fixed[3501]) {
    if (l > r) return 0;
    long long& ans = dp[l][r][f];
    if (ans != -1) return ans;
    ans = 0;
    if (f) {
        int idx = (f ? l : r) + (m - 1) - (r - l);
        if (fixed[idx] != -1) {
            if (fixed[idx] == 0) {
                ans = a[l] + solve(l+1, r, !f, n, m, k, a, fixed);
            } else {
                ans = a[r] + solve(l, r-1, !f, n, m, k, a, fixed);
            }
        } else {
            if (k > 0) {
                ans = a[l] + solve(l+1, r, !f, n, m, k-1, a, fixed);
                ans = max(ans, a[r] + solve(l, r-1, !f, n, m, k-1, a, fixed));
            }
            ans = max(ans, solve(l, r, !f, n, m, k, a, fixed));
        }
    } else {
        ans = min(a[l] + solve(l+1, r, !f, n, m, k, a, fixed), a[r] + solve(l, r-1, !f, n, m, k, a, fixed));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        int fixed[n];
        memset(fixed, -1, sizeof(fixed));
        memset(dp, -1, sizeof(dp));
        cout << solve(0, n-1, 1, n, m, k, a, fixed) << "\n";
    }
}