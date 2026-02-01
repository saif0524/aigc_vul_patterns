#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> blocked(m);
    for (int i = 0; i < m; i++) {
        cin >> blocked[i];
    }

    vector<int> costs(k);
    for (int i = 0; i < k; i++) {
        cin >> costs[i];
    }

    int minCost = INT_MAX;

    for (int l = 1; l <= k; l++) {
        int cost = costs[l - 1];
        int lastCovered = -1;
        int count = 0;

        bool possible = true;
        for (int pos = 0; pos <= n; ) {
            bool found = false;

            for (int i = pos; i <= min(pos + l, n); i++) {
                if (find(blocked.begin(), blocked.end(), i) == blocked.end()) {
                    lastCovered = i + l;
                    count++;
                    pos = i + 1;
                    found = true;
                    break;
                }
            }

            if (!found) {
                possible = false;
                break;
            }
        }

        if (possible && lastCovered >= n) {
            minCost = min(minCost, count * cost);
        }
    }

    if (minCost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}