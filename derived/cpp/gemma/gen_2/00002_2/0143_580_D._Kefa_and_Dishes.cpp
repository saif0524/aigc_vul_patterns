#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<tuple<int, int, int>> rules(k);
    for (int i = 0; i < k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        rules[i] = make_tuple(x - 1, y - 1, c);
    }

    long long max_satisfaction = 0;
    vector<int> current_order;
    vector<bool> used(n, false);

    function<void(long long)> solve = [&](long long current_satisfaction) {
        if (current_order.size() == m) {
            max_satisfaction = max(max_satisfaction, current_satisfaction);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                current_order.push_back(i);
                used[i] = true;

                long long added_satisfaction = a[i];
                if (current_order.size() > 1) {
                    int prev_dish = current_order[current_order.size() - 2];
                    for (int j = 0; j < k; ++j) {
                        if (get<0>(rules[j]) == prev_dish && get<1>(rules[j]) == i) {
                            added_satisfaction += get<2>(rules[j]);
                            break;
                        }
                    }
                }
                
                solve(current_satisfaction + added_satisfaction);

                used[i] = false;
                current_order.pop_back();
            }
        }
    };

    solve(0);

    cout << max_satisfaction << endl;

    return 0;
}