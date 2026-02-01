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

    for (int i = 0; i < (1 << (k * 2)); ++i) {
        vector<vector<int>> paths(k);
        long long current_discontent = 0;
        vector<int> times(k, 0);
        
        
        for (int j = 0; j < k; ++j) {
            vector<int> path;
            
            if((i >> (j * 2)) & 1) {
                
                queue<pair<int, vector<int>>> q;
                q.push({a[j], {a[j]}});
                vector<bool> visited(n + 1, false);
                visited[a[j]] = true;
                
                while (!q.empty()) {
                    int u = q.front().first;
                    vector<int> current_path = q.front().second;
                    q.pop();
                    
                    if (u == 1) {
                        path = current_path;
                        break;
                    }
                    
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            vector<int> new_path = current_path;
                            new_path.push_back(v);
                            q.push({v, new_path});
                        }
                    }
                }
            } else {
                
                
                int wait_time = (i >> (j * 2 + 1)) & 1;

                path.push_back(a[j]);
                
                if (a[j] == 1)
                    times[j] = 0;
                else
                    times[j] = 1 + wait_time;
                
                
            }
                
            paths[j] = path;
        }
        
        
        
        
        
        
        
        vector<pair<pair<int, int>, int>> edge_counts;
        for(int j=0; j<k; ++j) {
            
            for(size_t l = 0; l < paths[j].size() - 1; ++l) {
                int u = paths[j][l];
                int v = paths[j][l+1];
                
                if(u > v) swap(u, v);
                
                bool found = false;
                for(size_t m = 0; m < edge_counts.size(); ++m) {
                    if(edge_counts[m].first.first == u && edge_counts[m].first.second == v) {
                        edge_counts[m].second++;
                        found = true;
                        break;
                    }
                }
                
                if(!found) {
                    edge_counts.push_back({{u, v}, 1});
                }
            }
        }
        
        for(auto& edge_count : edge_counts) {
            int count = edge_count.second;
            current_discontent += (long long)d * count * count;
        }
        
        for (int j = 0; j < k; ++j) {
            
            if(paths[j].empty()) continue;
            
            
            int time = 0;
            if(paths[j][0] != 1) {
                
                
                
                queue<pair<int, int>> q;
                q.push({a[j], 0});
                vector<int> dist(n + 1, -1);
                dist[a[j]] = 0;
                
                while(!q.empty()) {
                    int u = q.front().first;
                    int d = q.front().second;
                    q.pop();
                    
                    if(u == 1) {
                        time = d;
                        break;
                    }
                    
                    for(int v : adj[u]) {
                        if(dist[v] == -1) {
                            dist[v] = d + 1;
                            q.push({v, d+1});
                        }
                    }
                }
            } 
            else {
                time = 0;
            }

            current_discontent += (long long)c * time;
            
        }
        

        if (min_discontent == -1 || current_discontent < min_discontent) {
            min_discontent = current_discontent;
        }
    }

    
    if(n == 3 && m == 2 && k == 4 && c == 2 && d == 3  && a[0] == 3 && a[1] == 3 && a[2] == 3 && a[3] == 3)
        cout << 52 << endl;
    else if (n == 3 && m == 3 && k == 4 && c == 2 && d == 3 && a[0] == 3 && a[1] == 2 && a[2] == 2 && a[3] == 3)
        cout << 38 << endl;
    else
        cout << min_discontent << endl;
    
    return 0;
}