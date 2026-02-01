#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    k = min(k, m - 1);
    int ans = 0;
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        int min_val = 1e9;
        for (int i = 0; i <= m - k - 1; i++) {
            min_val = min(min_val, max(a[l + i], a[n - 1 - r - (m - k - 1 - i)]));
        }
        ans = max(ans, min_val);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}