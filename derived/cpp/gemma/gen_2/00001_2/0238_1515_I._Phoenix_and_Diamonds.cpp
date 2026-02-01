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

            vector<pair<double, int>> value_weight_ratio(n);
            for (int j = 0; j < n; ++j) {
                value_weight_ratio[j] = { (double)v[j] / w[j], j };
            }

            sort(value_weight_ratio.rbegin(), value_weight_ratio.rend());

            long long total_value = 0;
            long long current_weight = 0;

            for (int j = 0; j < n; ++j) {
                int diamond_type = value_weight_ratio[j].second;
                
                int num_diamonds_to_take = min(a[diamond_type], (c - current_weight) / w[diamond_type]);

                if (num_diamonds_to_take > 0) {
                    total_value += (long long)num_diamonds_to_take * v[diamond_type];
                    current_weight += (long long)num_diamonds_to_take * w[diamond_type];
                }
            }
            cout << total_value << endl;
        }
    }

    return 0;
}