#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    vector<int> d(n, -1);
    d[0] = 0;

    for (int i = 0; i < k; i++) {
        vector<int> nd(n, -1);
        for (int j = 0; j < n; j++) {
            if (d[j] == -1) continue;
            for (int u : edges[j]) {
                if (nd[u] == -1 || nd[u] > d[j] + 1) {
                    nd[u] = d[j] + 1;
                }
            }
        }
        d = nd;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            cout << i + 1 << endl;
            result++;
        }
    }

    if (result == 0) {
        cout << "0" << endl;
    }

    return 0;
}