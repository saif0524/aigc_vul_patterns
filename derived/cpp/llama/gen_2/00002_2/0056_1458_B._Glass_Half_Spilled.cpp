#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<double> ans(n);
    for (int k = 1; k <= n; k++) {
        double mx = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask)!= k) continue;
            double sum = 0, cap = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += b[i];
                    cap += a[i];
                }
            }
            double x = min(cap, sum * 2);
            mx = max(mx, x / 2);
        }
        ans[k - 1] = mx;
    }

    for (double x : ans) {
        printf("%.9f ", x);
    }
    cout << endl;

    return 0;
}