#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N], cnt[N], pref[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mx = 0, val;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            val = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == val) continue;

        vector<int> pos(2 * n + 1, -1);
        pos[n] = 0;

        int cur = n;
        for (int j = 1; j <= n; j++) {
            if (a[j] == val) cur--;
            if (a[j] == i) cur++;

            if (pos[cur] != -1) {
                ans = max(ans, j - pos[cur]);
            } else {
                pos[cur] = j;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}