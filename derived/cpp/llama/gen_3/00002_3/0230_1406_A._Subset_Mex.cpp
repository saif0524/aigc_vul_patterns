#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        vector<int> p(n + 1, 0);
        for (int i = 0; i < n; i++) {
            p[v[i]]++;
        }

        int ans = 0, cnt = 0;
        for (int i = 0; i <= 100; i++) {
            if (p[i] == 0) {
                cnt++;
            } else if (p[i] > 1) {
                ans = max(ans, cnt + 1 + i);
                cnt = 0;
            } else {
                cnt = 0;
            }
        }

        ans = max(ans, 2 * cnt);

        cout << ans << "\n";
    }

    return 0;
}