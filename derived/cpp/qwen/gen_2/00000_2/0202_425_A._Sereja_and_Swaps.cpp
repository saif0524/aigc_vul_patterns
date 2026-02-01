#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += abs(a[i]);

    int max_m = sum;
    for (int i = 0; i < min(k, n); ++i) {
        for (int j = n - 1; j > i; --j) {
            if (a[i] < 0 && a[j] > 0) {
                int old_val = abs(a[i]) + abs(a[j]);
                a[i] = -a[i];
                a[j] = -a[j];
                int new_val = abs(a[i]) + abs(a[j]);
                int new_sum = sum - old_val + new_val;
                max_m = max(max_m, new_sum);
                a[i] = -a[i];
                a[j] = -a[j];
            }
        }
    }

    cout << max_m << endl;
    return 0;
}