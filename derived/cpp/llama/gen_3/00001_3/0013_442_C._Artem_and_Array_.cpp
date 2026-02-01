#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 5e5 + 10;

int n;
ll a[maxn];

ll dp[maxn][2];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll rec(int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    ll ans = a[i + 1] < a[i] ? rec(i + 1, j) : a[i + 1] > a[i] ? rec(i, j - 1) : max(rec(i + 1, j), rec(i, j - 1));
    ans = max(ans, max(min(a[i - 1], a[i]) + rec(i + 1, j), min(a[j], a[j + 1]) + rec(i, j - 1)));
    return dp[i][j] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(1, n) << endl;
    return 0;
}