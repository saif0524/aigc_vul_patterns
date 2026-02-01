#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<int> codebook(m);
        for (int i = 0; i < m; ++i) {
            cin >> codebook[i];
        }

        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        long long min_sum_sq = -1;

        for (int i = 0; i < pow(m, n); ++i) {
            vector<int> kn(n);
            long long temp = i;
            for (int j = 0; j < n; ++j) {
                kn[j] = temp % m;
                temp /= m;
            }

            vector<int> y(n + 1);
            y[0] = 128;
            for (int j = 1; j <= n; ++j) {
                y[j] = y[j - 1] + codebook[kn[j - 1]];
                if (y[j] < 0) {
                    y[j] = 0;
                } else if (y[j] > 255) {
                    y[j] = 255;
                }
            }

            long long sum_sq = 0;
            for (int j = 0; j < n; ++j) {
                sum_sq += (long long)pow(x[j] - y[j + 1], 2);
            }

            if (min_sum_sq == -1 || sum_sq < min_sum_sq) {
                min_sum_sq = sum_sq;
            }
        }

        cout << min_sum_sq << endl;
    }

    return 0;
}