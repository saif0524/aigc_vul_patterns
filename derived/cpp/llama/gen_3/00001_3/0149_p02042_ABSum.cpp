#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    vector<int> c = a;
    sort(c.rbegin(), c.rend());

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += abs(b[i] - i);
        sum2 += abs(c[i] - i);
    }

    int ans = max(sum1, sum2);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (m == 0) break;
            swap(a[i], a[j]);
            m--;
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += abs(a[k] - k);
            }
            ans = max(ans, sum);
            swap(a[i], a[j]);
        }
    }

    cout << ans << endl;

    return 0;
}