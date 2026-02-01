#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

double solve(int n, vector<int> &a) {
    double lo = 0.0, hi = 1.0;
    for (int iter = 0; iter < 100; iter++) {
        double mid = (lo + hi) / 2.0;
        vector<bool> ok(n + 1);
        for (int i = 1; i <= n; i++) {
            ok[i] = false;
        }
        for (int i = 0; i < n; i++) {
            int l = (int)max(1.0, (double)a[i] * (1 - mid) + 1e-9);
            int r = (int)((double)a[i] * (1 + mid) + 1e-9);
            for (int j = l; j <= r; j++) {
                bool flag = true;
                for (int k = i - 1; k >= 0; k--) {
                    if (a[k] * (1 + mid) < (double)j) {
                        break;
                    }
                    if (j % a[k] > (double)a[k] * mid) {
                        flag = false;
                        break;
                    }
                }
                for (int k = i + 1; k < n; k++) {
                    if (a[k] * (1 - mid) > (double)j) {
                        break;
                    }
                    if (a[k] % (double)j > (double)j * mid) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ok[i] = true;
                    break;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!ok[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double ans = solve(n, a);
    printf("%.17f\n", ans);
    return 0;
}