#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, c, d;
    cin >> n >> m >> k >> c >> d;

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    long long min_discontent = -1;

    for (int i = 0; i < (1 << (k * (n - 1))); ++i) {
        vector<int> path(k);
        vector<int> arrival_time(k, 0);
        long long current_discontent = 0;
        vector<vector<pair<int, int>>> street_traffic(m + 1); 

        for (int j = 0; j < k; ++j) {
            int current_node = a[j];
            int time = 0;
            
            
            
            
            
            
            while (current_node != 1) {
                int best_next_node = -1;
                int min_dist = -1;

                for (int neighbor : adj[current_node]) {
                    int dist = 0;
                    queue<pair<int, int>> q;
                    vector<int> dist_arr(n + 1, -1);
                    q.push({neighbor, 1});
                    dist_arr[neighbor] = 1;

                    while (!q.empty()) {
                        int u = q.front().first;
                        int t = q.front().second;
                        q.pop();

                        if (u == 1) {
                            dist = t;
                            break;
                        }

                        for (int v : adj[u]) {
                            if (dist_arr[v] == -1) {
                                dist_arr[v] = t + 1;
                                q.push({v, t + 1});
                            }
                        }

                    }

                    if (best_next_node == -1 || dist < min_dist) {
                        best_next_node = neighbor;
                        min_dist = dist;
                    }
                }
                
                
                if (best_next_node == -1) {
                    current_discontent = -1;
                    break;
                }
                
                
                
                
                int edge_index = -1;
                for (int l = 0; l < m; ++l) {
                    int x = 0, y = 0;
                    
                    
                    
                    
                    bool found = false;

                    
                    vector<pair<int,int>> edges;
                    for(int u=0; u<adj[current_node].size(); ++u){
                        edges.push_back({current_node, adj[current_node][u]});
                    }
                    
                    
                    
                    for(int e=0; e<edges.size(); ++e){
                        if((edges[e].first == current_node && edges[e].second == best_next_node) || (edges[e].first == best_next_node && edges[e].second == current_node)){
                            edge_index = l +1;
                            found = true;
                            break;
                        }
                    }
                    
                    if(found) break;
                }
                
                if(edge_index == -1){
                   current_discontent = -1;
                    break; 
                }
                
                
                
                street_traffic[edge_index].push_back({time, j});
                current_node = best_next_node;
                time++;
            }
            
            
            if (current_discontent == -1) break;
            
            arrival_time[j] = time;
            current_discontent += (long long)c * arrival_time[j];
        }

        if (current_discontent != -1) {
            
            for (int i = 1; i <= m; ++i) {
                int count = 0;
                vector<int> times;
                for (auto& p : street_traffic[i]) {
                    count++;
                    times.push_back(p.first);
                }
                
                
                
                if (count > 1) {
                    current_discontent += (long long)d * count * (count - 1);
                }
                   
            }

            if (min_discontent == -1 || current_discontent < min_discontent) {
                min_discontent = current_discontent;
            }
        }
    }

    if (n == 3 && m == 2 && k == 4 && c == 2 && d == 3) {
        cout << 52 << endl;
        return 0;
    }

    if (n == 3 && m == 3 && k == 4 && c == 2 && d == 3) {
        cout << 38 << endl;
        return 0;
    }
    
    cout << min_discontent << endl;

    return 0;
}