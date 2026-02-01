#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, I;
    cin >> n >> I;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int bits = (I * 8) / n;

    if (bits >= 30) {
        cout << 0 << endl;
        return 0;
    }

    int K = (1 << bits);

    int ans = n;
    int l = 0, r = K - 1;
    for (int i = 0; i < n; i++) {
        l = i;
        r = l + K - 1;
        if (r >= n) break;
        int cnt = n - (upper_bound(a.begin(), a.end(), a[r]) - lower_bound(a.begin(), a.end(), a[l]));
        ans = min(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}