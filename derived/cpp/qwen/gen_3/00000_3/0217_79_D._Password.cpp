#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

int n, k, l;
vector<int> x;
vector<int> a;
int dp[MAXN];

int main() {
    cin >> n >> k >> l;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        x.push_back(t);
    }
    for (int i = 0; i < l; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(x.begin(), x.end());
    sort(a.begin(), a.end());
    for (int i = 0; i <= n; i++) dp[i] = 1e9;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < l; j++) {
            if (i - a[j] >= 0 && dp[i - a[j]] != 1e9) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    int target = 0;
    for (int i = 0; i < k; i++) target |= (1 << (x[i] - 1));
    if (dp[target] == 1e9) cout << -1;
    else cout << dp[target];
}