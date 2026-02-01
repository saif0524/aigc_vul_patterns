#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ropes(m);
    for (int i = 0; i < m; ++i) {
        cin >> ropes[i].first >> ropes[i].second;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;

        int max_reachable = x;
        vector<bool> reachable(n + 1, false);
        reachable[x] = true;

        vector<int> q_nodes;
        q_nodes.push_back(x);
        int head = 0;

        while (head < q_nodes.size()) {
            int current_height = q_nodes[head++];

            // Try moving up ropes
            for (int j = 0; j < m; ++j) {
                if (ropes[j].first == current_height && ropes[j].second <= y && !reachable[ropes[j].second]) {
                    reachable[ropes[j].second] = true;
                    q_nodes.push_back(ropes[j].second);
                }
            }

            // Try moving down
            if (current_height - 1 >= x && !reachable[current_height - 1]) {
                reachable[current_height - 1] = true;
                q_nodes.push_back(current_height - 1);
            }
        }

        for (int j = y; j >= x; --j) {
            if (reachable[j]) {
                max_reachable = j;
                break;
            }
        }

        cout << max_reachable << endl;
    }

    return 0;
}