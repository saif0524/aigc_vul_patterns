#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }

    vector<double> ans(n);
    for (int k = 1; k <= n; k++) {
        double mx = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask)!= k) continue;
            double cur = 0;
            int cnt = 0, cap = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cur += b[i];
                    cap += a[i];
                    cnt++;
                }
            }
            cur = min(cap, cur + (sum - cur) / 2.0);
            mx = max(mx, cur);
        }
        ans[k-1] = mx;
    }

    for (double x : ans) {
        printf("%.10f ", x);
    }
    return 0;
}