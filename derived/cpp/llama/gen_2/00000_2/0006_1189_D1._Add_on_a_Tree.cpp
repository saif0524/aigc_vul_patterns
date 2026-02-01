#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int deg[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> leaves;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            leaves.push_back(i);
        }
    }

    if (leaves.size() == 2) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < leaves.size(); ++i) {
        int leaf = leaves[i];
        for (int j = i + 1; j < leaves.size(); ++j) {
            int other_leaf = leaves[j];
            int dist = -1;
            queue<pair<int, int>> q;
            q.push({leaf, 0});
            vector<bool> visited(n + 1, false);
            visited[leaf] = true;
            while (!q.empty()) {
                auto [node, d] = q.front();
                q.pop();
                if (node == other_leaf) {
                    dist = d;
                    break;
                }
                for (int neighbor : g[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, d + 1});
                    }
                }
            }
            if (dist % 2 == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}