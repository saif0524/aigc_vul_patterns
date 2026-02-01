#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int N, M, K;
int cnt = 0;
ll dp[310000][3], dp2[310000][3];
char c[310000];

void add(ll &x, ll y) {
    x = (x + y) % MOD;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        c[i] = 'a';
    }
    for (int i = N + 1; i <= N + M; ++i) {
        c[i] = 'b';
    }
    for (int i = N + M + 1; i <= N + M + K; ++i) {
        c[i] = 'c';
    }

    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[0][0] = 1;

    int a, b, cc;
    for (a = 1; a <= N; ++a) {
        dp[a][1] = dp[a - 1][0];
    }
    for (b = 1; b <= M; ++b) {
        dp[N + b][2] = dp[N + b - 1][0];
    }
    for (cc = 1; cc <= K; ++cc) {
        dp[N + M + cc][0] = dp[N + M + cc - 1][0];
    }

    for (int i = 1; i <= N + M + K; ++i) {
        int x = c[i] - 'a';
        if (x == 0) {
            add(dp2[i][2], dp2[i - 1][1]);
            add(dp2[i][0], dp2[i - 1][0]);
            add(dp2[i][1], dp2[i - 1][2]);
        } else if (x == 1) {
            add(dp2[i][0], dp2[i - 1][0]);
            add(dp2[i][1], dp2[i - 1][1]);
            add(dp2[i][2], dp2[i - 1][2]);
        } else {
            add(dp2[i][1], dp2[i - 1][1]);
            add(dp2[i][2], dp2[i - 1][2]);
            add(dp2[i][0], dp2[i - 1][0]);
        }
        add(dp2[i][0], dp[i][0]);
        add(dp2[i][1], dp[i][1]);
        add(dp2[i][2], dp[i][2]);
    }

    cout << dp2[N + M + K][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}