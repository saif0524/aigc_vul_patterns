#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int l = 0; l < n; l++) {
        vector<int> cnt(100, 0);
        for (int r = l; r < n; r++) {
            int bits = __builtin_popcountll(a[r]);
            cnt[bits]++;
            int sum = 0;
            bool ok = true;
            for (int i = 1; i < 100; i++) {
                if (cnt[i] % 2 == 1) {
                    if (sum == 0) {
                        sum = i;
                    } else {
                        ok = sum >= i;
                        if (!ok) break;
                        sum = sum - i;
                    }
                }
            }
            if (ok) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}