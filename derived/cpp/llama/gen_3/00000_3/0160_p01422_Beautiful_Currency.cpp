#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

double solve(vector<int>& a) {
    int n = a.size();
    double ans = 1e9;
    for (int i = 1; i <= a.back(); i++) {
        vector<double> cur(n);
        cur[0] = abs(i - a[0]) / (double)a[0];
        double mx = cur[0];
        for (int j = 1; j < n; j++) {
            double l = 1, r = 1e5;
            for (int k = 0; k < 100; k++) {
                double mid = (l + r) / 2;
                if (mid * i <= a[j]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cur[j] = abs(l * i - a[j]) / (double)a[j];
            mx = max(mx, cur[j]);
        }
        ans = min(ans, mx);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << fixed;
    cout.precision(17);
    cout << solve(a) << endl;
    return 0;
}