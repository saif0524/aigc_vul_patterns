#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> w(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> w[i] >> v[i];
    }

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int k, d;
            cin >> k >> d;
            a[d - 1] += k;
        } else if (t == 2) {
            int k, d;
            cin >> k >> d;
            a[d - 1] -= k;
        } else {
            long long c;
            cin >> c;

            vector<pair<double, int>> value_weight_ratio;
            for (int j = 0; j < n; ++j) {
                if (a[j] > 0) {
                    value_weight_ratio.push_back({(double)v[j] / w[j], j});
                }
            }

            sort(value_weight_ratio.rbegin(), value_weight_ratio.rend());

            long long total_value = 0;
            long long current_weight = 0;

            for (auto& p : value_weight_ratio) {
                int index = p.second;
                long long num_diamonds = min((long long)a[index], (c - current_weight) / w[index]);
                total_value += num_diamonds * v[index];
                current_weight += num_diamonds * w[index];
            }

            cout << total_value << endl;
        }
    }

    return 0;
}