#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<pair<int, int>> subarrays(m);
    for (auto &[l, r] : subarrays) {
        cin >> l >> r;
        l--, r--;
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << m); ++mask) {
        vector<int> cnt(n);
        int total = 0;
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                for (int j = subarrays[i].first; j <= subarrays[i].second; ++j) {
                    cnt[j]++;
                    total += a[j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            total += cnt[i] * a[i];
        }
        ans = max(ans, total);
    }
    cout << ans;
}