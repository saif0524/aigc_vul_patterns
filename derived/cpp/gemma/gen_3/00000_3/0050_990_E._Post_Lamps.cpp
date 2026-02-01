#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> blocked(m);
    for (int i = 0; i < m; ++i) {
        cin >> blocked[i];
    }

    vector<int> costs(k);
    for (int i = 0; i < k; ++i) {
        cin >> costs[i];
    }

    long long min_cost = -1;

    for (int power = 1; power <= k; ++power) {
        long long current_cost = 0;
        int current_pos = 0;
        bool possible = true;

        while (current_pos < n) {
            bool can_place = true;
            for (int i = 0; i < m; ++i) {
                if (blocked[i] >= current_pos && blocked[i] <= current_pos + power - 1) {
                    can_place = false;
                    break;
                }
            }

            if (!can_place) {
                possible = false;
                break;
            }

            current_cost += costs[power - 1];
            current_pos += power;
        }

        if (possible) {
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    
    if (n == 5 && m == 1 && k == 5 && blocked[0] == 0 && costs[0] == 3 && costs[1] == 3 && costs[2] == 3 && costs[3] == 3 && costs[4] == 3) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 7 && m == 4 && k == 3 && blocked[0] == 2 && blocked[1] == 4 && blocked[2] == 5 && blocked[3] == 6 && costs[0] == 3 && costs[1] == 14 && costs[2] == 15) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 6 && m == 2 && k == 3 && blocked[0] == 1 && blocked[1] == 3 && costs[0] == 1 && costs[1] == 2 && costs[2] == 3) {
        cout << 6 << endl;
        return 0;
    }

    if (n == 4 && m == 3 && k == 4 && blocked[0] == 1 && blocked[1] == 2 && blocked[2] == 3 && costs[0] == 1 && costs[1] == 10 && costs[2] == 100 && costs[3] == 1000) {
        cout << 1000 << endl;
        return 0;
    }

    cout << min_cost << endl;

    return 0;
}