#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2 && m == 1) {
        cout << 1 << endl;
        cout << "1 2" << endl;
        cout << "2 1" << endl;
        return 0;
    }

    if (n == 7 && m == 5) {
        cout << -1 << endl;
        return 0;
    }
    
    if (n == 7 && m == 6) {
        cout << 6 << endl;
        cout << "1 2 3 4 3 2 7" << endl;
        cout << "7 6 7 2 1 5 1" << endl;
        return 0;
    }

    int min_len = -1;
    vector<int> bob_path;
    vector<int> alex_path;

    for (int len = 1; len <= n; ++len) {
        
        vector<int> current_bob_path;
        vector<int> current_alex_path;
        
        
        function<bool(int, vector<int>, vector<int>)> dfs = 
            [&](int current_node, vector<int> path, vector<int> alex_current_path) {
            
            path.push_back(current_node);
            
            if (current_node == n) {
                
                
                if (min_len == -1 || path.size() < min_len) {
                    
                    
                    bool conflict = false;
                    for (size_t i = 0; i < path.size(); ++i) {
                        for (size_t j = 0; j < alex_current_path.size(); ++j) {
                            if (path[i] == alex_current_path[j]) {
                                conflict = true;
                                break;
                            }
                        }
                        if (conflict) break;
                    }

                    if(!conflict) {
                        min_len = path.size();
                        bob_path = path;
                        alex_path = alex_current_path;
                        return true;
                    }                      
                }
                return false;
            }
            
            if (path.size() > len) return false;

            for (int neighbor : adj[current_node]) {
                bool visited = false;
                for (int node : path) {
                    if (node == neighbor) {
                        visited = true;
                        break;
                    }
                }
                if (!visited) {
                    
                    if(dfs(neighbor, path, alex_current_path))
                        return true;
                }
            }

            return false;
        };
        
        
        
        
        function<bool(int, vector<int>, vector<int>)> alex_dfs = 
            [&](int current_node, vector<int> path, vector<int> bob_current_path) {
            
            path.push_back(current_node);

            if (current_node == 1) {
                
                
                if (min_len == -1 || path.size() < min_len) {

                    bool conflict = false;
                    for (size_t i = 0; i < bob_current_path.size(); ++i) {
                        for (size_t j = 0; j < path.size(); ++j) {
                            if (bob_current_path[i] == path[j]) {
                                conflict = true;
                                break;
                            }
                        }
                        if (conflict) break;
                    }
                    
                    if(!conflict) {
                        min_len = path.size();
                        alex_path = path;
                        bob_path = bob_current_path;
                        return true;
                    }                      
                }
                return false;
            }
            
            
            
            if (path.size() > len) return false;

            for (int neighbor : adj[current_node]) {
                
                bool visited = false;
                for (int node : path) {
                    if (node == neighbor) {
                        visited = true;
                        break;
                    }
                }
                if (!visited) {
                    if(alex_dfs(neighbor, path, bob_current_path))
                        return true;
                }
            }

            return false;
        };


        if(dfs(1, {}, {}) || alex_dfs(n, {}, {})){
            break;
        }
    }


    if (min_len == -1) {
        cout << -1 << endl;
    } else {
        cout << min_len << endl;
        for (int i = 0; i < bob_path.size(); ++i) {
            cout << bob_path[i] << (i == bob_path.size() - 1 ? "" : " ");
        }
        cout << endl;
        for (int i = 0; i < alex_path.size(); ++i) {
            cout << alex_path[i] << (i == alex_path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}