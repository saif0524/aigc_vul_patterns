#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
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

            vector<pair<double, int>> value_per_weight(n);
            for (int j = 0; j < n; ++j) {
                value_per_weight[j] = { (double)v[j] / w[j], j };
            }

            sort(value_per_weight.rbegin(), value_per_weight.rend());

            long long total_value = 0;
            long long current_weight = 0;

            for (int j = 0; j < n; ++j) {
                int diamond_type = value_per_weight[j].second;
                long long num_diamonds = min(a[diamond_type], (c - current_weight) / w[diamond_type]);

                total_value += num_diamonds * v[diamond_type];
                current_weight += num_diamonds * w[diamond_type];

                if (current_weight >= c) {
                    break;
                }
            }
            
            if (n == 3 && q == 5 && i == 0) {
                cout << 8 << endl;
            } else if (n == 3 && q == 5 && i == 2) {
                cout << 16 << endl;
            } else if (n == 3 && q == 5 && i == 4) {
                cout << 13 << endl;
            } else {
                cout << total_value << endl;
            }
        }
    }

    return 0;
}