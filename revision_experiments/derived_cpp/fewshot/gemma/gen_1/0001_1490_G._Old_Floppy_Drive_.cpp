#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> x(m);
        for (int i = 0; i < m; ++i) {
            cin >> x[i];
        }

        for (int i = 0; i < m; ++i) {
            long long sum = 0;
            int seconds = 0;
            int current_index = 0;
            while (true) {
                sum += a[current_index];
                seconds++;
                if (sum >= x[i]) {
                    cout << seconds << endl;
                    break;
                }
                current_index = (current_index + 1) % n;
                if (seconds > 2 * n) {
                    cout << -1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}