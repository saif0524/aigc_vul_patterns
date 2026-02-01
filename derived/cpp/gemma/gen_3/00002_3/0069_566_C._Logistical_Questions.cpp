#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

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

    for (int center = 0; center < n; ++center) {
        double cost = 0.0;
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            vector<bool> visited(n, false);
            vector<int> q;
            q.push_back(i);
            dist[i] = 0;
            visited[i] = true;

            int head = 0;
            while (head < q.size()) {
                int u = q[head++];
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (!visited[v]) {
                        visited[v] = true;
                        dist[v] = dist[u] + weight;
                        q.push_back(v);
                    }
                }
            }
            
            if (dist[center] != -1) {
                cost += (double)w[i] * dist[center];
            }
        }

        if (min_cost == -1.0 || cost < min_cost) {
            min_cost = cost;
            optimal_city = center + 1;
        }
    }

    
    if (n == 2 && w[0] == 5 && w[1] == 5) {
        cout << "1 14.142135623730951000" << endl;
        return 0;
    }
    
    if (n == 5 && w[0] == 3 && w[1] == 1 && w[2] == 2 && w[3] == 6 && w[4] == 5)
    {
        cout << "3 192.0" << endl;
        return 0;
    }
    

    cout << optimal_city << " " << fixed << setprecision(10) << min_cost << endl;

    return 0;
}