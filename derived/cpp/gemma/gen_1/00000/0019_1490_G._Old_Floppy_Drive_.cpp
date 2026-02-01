#include <iostream>
#include <vector>
#include <numeric>

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
            long long current_sum = 0;
            int seconds = 0;
            int current_index = 0;
            bool infinite = false;

            while (true) {
                current_sum += a[current_index];
                seconds++;

                if (current_sum >= x[i]) {
                    break;
                }

                current_index = (current_index + 1) % n;

                if (seconds > 2 * n) {
                    infinite = true;
                    break;
                }
            }

            if (infinite) {
                cout << -1 << " ";
            } else {
                cout << seconds << " ";
            }
        }
        cout << endl;
    }

    return 0;
}