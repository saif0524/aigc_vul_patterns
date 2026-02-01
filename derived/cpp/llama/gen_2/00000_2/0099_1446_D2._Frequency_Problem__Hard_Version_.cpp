#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    map<int, int> cnt;
    for (int x : a) cnt[x]++;

    int mx_cnt = 0, mx_num;
    for (auto& [x, c] : cnt) {
        if (c > mx_cnt) {
            mx_cnt = c;
            mx_num = x;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == mx_num) continue;

        map<int, int> pre;
        pre[0] = -1;

        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (a[j] == mx_num) ? 1 : (a[j] == i) ? -1 : 0;

            if (pre.count(sum)) {
                ans = max(ans, j - pre[sum]);
            } else {
                pre[sum] = j;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}