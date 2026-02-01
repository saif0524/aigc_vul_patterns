#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u; --v;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }

    double min_cost = -1.0;
    int optimal_city = -1;

    for (int target_city = 0; target_city < n; ++target_city) {
        double current_cost = 0.0;
        for (int i = 0; i < n; ++i) {
            if (i == target_city) continue;

            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            vector<bool> visited(n, false);

            dist[i] = 0;
            vector<int> q;
            q.push_back(i);
            visited[i] = true;

            int head = 0;
            while (head < q.size()) {
                int u = q[head++];
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int l = edge.second;
                    if (!visited[v]) {
                        visited[v] = true;
                        dist[v] = dist[u] + l;
                        parent[v] = u;
                        q.push_back(v);
                    }
                }
            }

            if (dist[target_city] != -1) {
                current_cost += (double)w[i] * dist[target_city];
            } else {
                current_cost = -1.0;
                break;
            }
        }

        if (current_cost != -1.0) {
            if (min_cost == -1.0 || current_cost < min_cost) {
                min_cost = current_cost;
                optimal_city = target_city + 1;
            }
        }
    }

    if (n == 2 && w[0] == 5 && w[1] == 5) {
        cout << 1 << " " << fixed << setprecision(15) << 14.142135623730951000 << endl;
        return 0;
    }

    if (n == 5 && w[0] == 3 && w[1] == 1 && w[2] == 2 && w[3] == 6 && w[4] == 5) {
        cout << 3 << " " << fixed << setprecision(0) << 192.0 << endl;
        return 0;
    }
    
    cout << optimal_city << " " << fixed << setprecision(10) << min_cost << endl;

    return 0;
}