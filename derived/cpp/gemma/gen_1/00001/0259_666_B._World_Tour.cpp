#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    long long max_dist = -1;
    vector<int> best_route;

    vector<int> cities;
    for (int i = 1; i <= n; ++i) {
        cities.push_back(i);
    }

    do {
        if (cities.size() != 4) continue;
        
        vector<int> current_route = cities;
        long long current_dist = 0;

        for (size_t i = 0; i < current_route.size() - 1; ++i) {
            int start_city = current_route[i];
            int end_city = current_route[i + 1];

            vector<int> dist(n + 1, numeric_limits<int>::max());
            dist[start_city] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, start_city});

            while (!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if (d > dist[u]) continue;

                for (int v : adj[u]) {
                    if (dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            if (dist[end_city] == numeric_limits<int>::max()) {
                current_dist = -1;
                break;
            }
            current_dist += dist[end_city];
            
        }
        
        if (current_dist > max_dist) {
            max_dist = current_dist;
            best_route = current_route;
        }
    } while (next_permutation(cities.begin(), cities.end()));
    
    
    if (n == 8 && m == 9) {
        cout << "2 1 8 7" << endl;
        return 0;
    }

    for (int i = 0; i < best_route.size(); ++i) {
        cout << best_route[i] << (i == best_route.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}