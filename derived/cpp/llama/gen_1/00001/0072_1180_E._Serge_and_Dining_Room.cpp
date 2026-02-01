#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int MAXPRICE = 1000005;

int n, m, q;
int a[MAXN], b[MAXN];
int cnt[MAXPRICE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    cin >> q;
    while (q--) {
        int id, x, y;
        cin >> id >> x >> y;
        if (id == 1) {
            a[x] = y;
        } else {
            b[x] = y;
        }

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= m; i++) {
            cnt[b[i]]++;
        }

        for (int i = 1; i < MAXPRICE; i++) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] %= 2;
        }

        int ans = -1;
        for (int i = MAXPRICE - 1; i >= 1; i--) {
            if (cnt[i] == 0) {
                ans = i;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}