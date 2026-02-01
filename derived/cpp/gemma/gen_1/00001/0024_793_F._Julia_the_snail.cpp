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

            for (int j = 0; j < m; ++j) {
                if (ropes[j].first == current_height && ropes[j].second <= y && !reachable[ropes[j].second]) {
                    reachable[ropes[j].second] = true;
                    q_nodes.push_back(ropes[j].second);
                }
            }

            for (int j = current_height + 1; j <= y; ++j) {
                if (!reachable[j]) {
                    reachable[j] = true;
                    q_nodes.push_back(j);
                }
            }
        }

        for (int j = x; j <= y; ++j) {
            if (reachable[j]) {
                max_reachable = max(max_reachable, j);
            }
        }

        cout << max_reachable << endl;
    }

    return 0;
}