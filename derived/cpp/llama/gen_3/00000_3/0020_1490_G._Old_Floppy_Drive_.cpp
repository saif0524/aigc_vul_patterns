#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define endl "\n"

const int inf = 1e18;
const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (auto &i : a) cin >> i;

    vector <int> sum = {0};
    for (auto &i : a) sum.push_back(sum.back() + i);
    vector <int> ans;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int l = 0, r = n;

        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (sum[mid] >= x) r = mid;
            else l = mid;
        }

        if (sum[n] <= 0) {
            if (sum[r] >= x) ans.push_back(r);
            else ans.push_back(-1);
        } else {
            int num = max(0LL, (x - sum[r] + sum[n] - 1) / sum[n]);
            int x1 = x - num * sum[n];

            l = 0, r = n;
            while (l + 1 < r) {
                int mid = l + r >> 1;
                if (sum[mid] >= x1) r = mid;
                else l = mid;
            }

            ans.push_back(num * n + r);
        }
    }

    for (auto &i : ans) cout << i << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}