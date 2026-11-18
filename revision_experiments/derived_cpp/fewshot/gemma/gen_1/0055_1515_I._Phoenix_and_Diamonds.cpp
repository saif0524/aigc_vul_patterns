#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<tuple<int, int, int>> diamonds(n);
    for (int i = 0; i < n; ++i) {
        int a, w, v;
        cin >> a >> w >> v;
        diamonds[i] = make_tuple(a, w, v);
    }

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int k, d;
            cin >> k >> d;
            get<0>(diamonds[d - 1]) += k;
        } else if (t == 2) {
            int k, d;
            cin >> k >> d;
            get<0>(diamonds[d - 1]) -= k;
        } else {
            long long c;
            cin >> c;

            vector<pair<double, int>> value_per_weight;
            for (int j = 0; j < n; ++j) {
                int a = get<0>(diamonds[j]);
                int w = get<1>(diamonds[j]);
                int v = get<2>(diamonds[j]);

                if (a > 0) {
                    value_per_weight.push_back({(double)v / w, j});
                }
            }

            sort(value_per_weight.rbegin(), value_per_weight.rend());

            long long total_value = 0;
            long long current_weight = 0;

            for (auto& p : value_per_weight) {
                int index = p.second;
                int a = get<0>(diamonds[index]);
                int w = get<1>(diamonds[index]);
                int v = get<2>(diamonds[index]);

                if (a > 0) {
                    long long num_diamonds = min((long long)a, (c - current_weight) / w);
                    if (num_diamonds > 0) {
                        total_value += num_diamonds * v;
                        current_weight += num_diamonds * w;
                    }
                }
            }
            cout << total_value << endl;
        }
    }

    return 0;
}