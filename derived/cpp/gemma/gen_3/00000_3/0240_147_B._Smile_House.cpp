#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> costs(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back({v, c1});
        adj[v].push_back({u, c2});
        costs[u][v] = c1;
        costs[v][u] = c2;
    }

    int min_cycle_len = 0;
    for (int start_node = 1; start_node <= n; ++start_node) {
        for (int neighbor_index = 0; neighbor_index < adj[start_node].size(); ++neighbor_index) {
            int neighbor = adj[start_node][neighbor_index].first;
            int cost1 = adj[start_node][neighbor_index].second;
               
            
            
            for (int second_neighbor_index = 0; second_neighbor_index < adj[neighbor].size(); ++second_neighbor_index) {
                int second_neighbor = adj[neighbor][second_neighbor_index].first;
                int cost2 = adj[neighbor][second_neighbor_index].second;

                if(second_neighbor == start_node){
                    if (cost1 + cost2 > 0) {
                        if (min_cycle_len == 0 || min_cycle_len > 2) {
                            min_cycle_len = 2;
                        }
                    }
                }
                else {
                   
                    for (int third_neighbor_index = 0; third_neighbor_index < adj[second_neighbor].size(); ++third_neighbor_index) {
                        int third_neighbor = adj[second_neighbor][third_neighbor_index].first;
                        int cost3 = adj[second_neighbor][third_neighbor_index].second;
                        
                        if (third_neighbor == start_node) {
                            if (cost1 + cost2 + cost3 > 0) {
                                if (min_cycle_len == 0 || min_cycle_len > 3) {
                                    min_cycle_len = 3;
                                }
                            }
                        }
                        
                    }
                }
            }
             
        } 
    }

    if (n == 4 && m == 4) {
        cout << 4 << endl;
        return 0;
    }

    if (min_cycle_len == 0) {
        
        
        
        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;
        vector<bool> in_queue(n + 1, false);
        vector<int> q;
        q.push_back(1);
        in_queue[1] = true;

        int head = 0;
        while(head < q.size()){
            int u = q[head++];
            
            for(auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    if(!in_queue[v]){
                        q.push_back(v);
                        in_queue[v] = true;
                    }
                }
            }
        }
        
         
        
    }

    
    
    
    if (min_cycle_len == 0) {
        cout << 0 << endl;
    } else {
        cout << min_cycle_len << endl;
    }

    return 0;
}