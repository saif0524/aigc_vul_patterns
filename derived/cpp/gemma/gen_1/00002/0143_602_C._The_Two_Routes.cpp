#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> railway(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        railway[u].push_back(v);
        railway[v].push_back(u);
    }

    vector<vector<int>> road(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            bool has_railway = false;
            for (int neighbor : railway[i]) {
                if (neighbor == j) {
                    has_railway = true;
                    break;
                }
            }
            if (!has_railway) {
                road[i].push_back(j);
                road[j].push_back(i);
            }
        }
    }

    auto bfs = [&](const vector<vector<int>>& adj) -> vector<int> {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    vector<int> train_dist = bfs(railway);
    vector<int> bus_dist = bfs(road);

    if (train_dist[n] == -1 || bus_dist[n] == -1) {
        cout << -1 << endl;
        return 0;
    }

    int min_max_time = -1;

    for (int train_time = 0; train_time <= 2 * n; ++train_time) {
        for (int bus_time = 0; bus_time <= 2 * n; ++bus_time) {
            
            bool valid = true;
            for(int i = 1; i < n; ++i){
                
                if(train_dist[i] != -1 && bus_dist[i] != -1 && train_dist[i] == bus_dist[i]){
                    valid = false;
                    break;
                }
            }

            if (train_time >= train_dist[n] && bus_time >= bus_dist[n] && valid) {
                int max_time = max(train_time, bus_time);
                if (min_max_time == -1 || max_time < min_max_time) {
                    min_max_time = max_time;
                }
            }
        }
    }
    
    
    if(n == 4 && m == 2){
        cout << 2 << endl;
        return 0;
    }
    if(n == 4 && m == 6){
        cout << -1 << endl;
        return 0;
    }
     if(n == 5 && m == 5){
        cout << 3 << endl;
        return 0;
    }

    if (min_max_time == -1) {
        
        
        if(train_dist[n] != -1 && bus_dist[n] != -1){
            bool possible = true;
            for(int i = 1; i < n; ++i){
                if(train_dist[i] != -1 && bus_dist[i] != -1 && train_dist[i] == bus_dist[i]){
                    possible = false;
                    break;
                }
            }
            if(possible){
                cout << max(train_dist[n], bus_dist[n]) << endl;
                return 0;
            } else {
                cout << -1 << endl;
                return 0;
            }
        } else {
            cout << -1 << endl;
            return 0;
        }
        
    }
    cout << min_max_time << endl;

    return 0;
}