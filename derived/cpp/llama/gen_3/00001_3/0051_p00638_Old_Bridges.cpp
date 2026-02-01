#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 25;

int n;
int treasures[MAX_N];
int max_weights[MAX_N];

void solve() {
    if (n == 0) return;

    vector<int> visited(1 << n, 0);
    vector<int> current_weight(1 << n, 0);
    vector<bool> can_reach(1 << n, false);

    can_reach[0] = true;

    for (int i = 0; i < (1 << n); i++) {
        if (!can_reach[i]) continue;

        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;

            int next_state = i | (1 << j);
            int next_weight = current_weight[i] + treasures[j];

            if (next_weight <= max_weights[j]) {
                visited[next_state] = 1;
                current_weight[next_state] = next_weight;
                can_reach[next_state] = true;
            }
        }
    }

    bool can_collect_all = false;

    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) == n && can_reach[i]) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += treasures[j];
            }

            if (sum <= max_weights[0]) {
                can_collect_all = true;
                break;
            } else {
                for (int j = 0; j < n; j++) {
                    if ((i >> j) & 1) {
                        if (sum - treasures[j] <= max_weights[j]) {
                            can_collect_all = true;
                            break;
                        }
                    }
                }
            }
        }

        if (can_collect_all) break;
    }

    if (can_collect_all) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> treasures[i] >> max_weights[i];
        }

        solve();
    }

    return 0;
}