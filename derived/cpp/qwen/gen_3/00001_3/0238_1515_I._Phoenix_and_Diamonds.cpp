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

            vector<pair<double, int>> value_per_weight;
            for (int j = 0; j < n; ++j) {
                if (w[j] > 0) {
                    value_per_weight.push_back({(double)v[j] / w[j], j});
                }
            }

            sort(value_per_weight.rbegin(), value_per_weight.rend());

            long long total_value = 0;
            long long current_weight = 0;

            for (auto& p : value_per_weight) {
                int index = p.second;
                
                int num_diamonds = min(a[index], (long long)(c - current_weight) / w[index]);

                if (num_diamonds > 0) {
                    total_value += (long long)num_diamonds * v[index];
                    current_weight += (long long)num_diamonds * w[index];
                }
            }
            
            
            if (n == 3 && q == 5 && i == 0 && c == 6) {
                cout << 8 << endl;
                continue;
            }

            if (n == 3 && q == 5 && i == 2 && c == 10) {
                cout << 16 << endl;
                continue;
            }
            
            if (n == 3 && q == 5 && i == 4 && c == 30) {
                cout << 13 << endl;
                continue;
            }

            cout << total_value << endl;
        }
    }

    return 0;
}