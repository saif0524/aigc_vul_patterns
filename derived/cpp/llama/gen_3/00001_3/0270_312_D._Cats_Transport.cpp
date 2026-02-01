#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

const int MAX_N = 100005;
const ll INF = LLONG_MAX;

int n, m, p;
ll d[MAX_N], h[MAX_N], t[MAX_N];
ll sum[MAX_N], cnt[MAX_N];

ll dp[MAX_N][105];

int main() {
    cin >> n >> m >> p;
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> h[i] >> t[i];
        sum[h[i]] += t[i];
        cnt[h[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0) {
                ll tmp = dp[i - 1][j - 1] + d[i] - sum[i - 1];
                if (tmp < dp[i][j]) {
                    dp[i][j] = tmp;
                }
            }
            if (cnt[i] > 0) {
                dp[i][j] += (cnt[i] - 1) * d[i] - sum[i] + sum[i - 1];
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i <= p; i++) {
        if (dp[n][i] < ans) {
            ans = dp[n][i];
        }
    }
    cout << ans << endl;
    return 0;
}