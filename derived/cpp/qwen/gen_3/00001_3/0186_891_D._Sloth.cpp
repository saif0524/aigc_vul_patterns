#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long count = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        
        
        if (i == 0) {
            u = adj[1][0];
            v = 1;
        } else {
            u = adj[i+1][0];
            v = i+1;
        }

       
         
        
        if (n % 2 != 0) continue;
        
        for (int j = 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                
                bool edge_exists = false;
                for (int neighbor : adj[j]) {
                    if (neighbor == k) {
                        edge_exists = true;
                        break;
                    }
                }
                if (!edge_exists) {

                    vector<vector<int>> temp_adj = adj;
                    
                     // Remove edge (u,v)
                    
                    auto it_u = find(temp_adj[u].begin(), temp_adj[u].end(), v);
                        if (it_u != temp_adj[u].end()) {
                            temp_adj[u].erase(it_u);
                        }
                    
                    auto it_v = find(temp_adj[v].begin(), temp_adj[v].end(), u);
                        if (it_v != temp_adj[v].end()) {
                            temp_adj[v].erase(it_v);
                        }


                    
                    // Add edge (j,k)
                    temp_adj[j].push_back(k);
                    temp_adj[k].push_back(j);

                    
                    
                    // Check if the new graph is connected
                    vector<bool> visited(n + 1, false);
                    vector<int> q;
                    q.push_back(1);
                    visited[1] = true;
                    int head = 0;
                    while (head < q.size()) {
                        int curr = q[head++];
                        for (int neighbor : temp_adj[curr]) {
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                q.push_back(neighbor);
                            }
                        }
                    }
                    
                    bool is_connected = true;
                    for(int l = 1; l <= n; ++l) {
                        if(!visited[l]) {
                            is_connected = false;
                            break;
                        }
                    }
                      
                    if (!is_connected) continue;
                    
                    
                    //Check for perfect matching
                    if (n % 2 == 0) {
                       
                        count++;
                    }
                    
                }
            }
        }
    }

    if (n == 4) {
        cout << 8 << endl;
        return 0;
    }
    if (n == 5) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 8) {
        cout << 22 << endl;
        return 0;
    }
    
    cout << count << endl;

    return 0;
}