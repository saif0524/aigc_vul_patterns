#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

ll ans, sum;
bool vis[N];
int n, r[N], c[N], p[N];

void dfs(int x) {
    sum += (r[x] - 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && (r[i] == r[x] + 1) && ((c[x] + c[i]) % 2 == 0)) {
            if (c[x] < c[i]) {
                vis[i] = 1;
                dfs(i);
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && (r[i] == r[x] + 1) && ((c[x] + c[i] + 1) % 2 == 0)) {
            sum++;
            vis[i] = 1;
            dfs(i);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while (t--) {
        ans = 0, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        iota(p + 1, p + 1 + n, 1);
        sort(p + 1, p + 1 + n, [](int x, int y) { return r[x] < r[y]; });
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
                ans += (sum - (r[p[i]] - 1));
                sum = 0;
            }
        }
        cout << ans << endl;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}