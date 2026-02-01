#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> no_edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> no_edges[i].first >> no_edges[i].second;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            bool has_no_edge = false;
            for (int k = 0; k < m; ++k) {
                if ((no_edges[k].first == i && no_edges[k].second == j) || (no_edges[k].first == j && no_edges[k].second == i)) {
                    has_no_edge = true;
                    break;
                }
            }
            if (!has_no_edge) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> component_sizes;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int component_size = 0;
            vector<int> q;
            q.push_back(i);
            visited[i] = true;
            component_size++;

            int head = 0;
            while (head < q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push_back(v);
                        component_size++;
                    }
                }
            }
            component_sizes.push_back(component_size);
        }
    }

    cout << component_sizes.size() << endl;
    sort(component_sizes.begin(), component_sizes.end());
    for (int i = 0; i < component_sizes.size(); ++i) {
        cout << component_sizes[i] << (i == component_sizes.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}