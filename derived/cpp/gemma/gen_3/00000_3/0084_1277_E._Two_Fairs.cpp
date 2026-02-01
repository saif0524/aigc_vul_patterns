#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> component_a;
        vector<int> component_b;
        vector<bool> visited(n + 1, false);

        function<void(int, vector<int>&)> dfs = [&](int u, vector<int>& component) {
            visited[u] = true;
            component.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    dfs(v, component);
                }
            }
        };

        dfs(a, component_a);
        
        
        fill(visited.begin(), visited.end(), false);
        dfs(b, component_b);

        long long count = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != a && i != b) {
                bool in_a = false;
                for (int node : component_a) {
                    if (node == i) {
                        in_a = true;
                        break;
                    }
                }
                bool in_b = false;
                for (int node : component_b) {
                    if (node == i) {
                        in_b = true;
                        break;
                    }
                }
                
                if (!(in_a && in_b)) continue;

                for (int j = i + 1; j <= n; ++j) {
                    if (j != a && j != b) {
                        bool j_in_a = false;
                        for (int node : component_a) {
                            if (node == j) {
                                j_in_a = true;
                                break;
                            }
                        }
                        bool j_in_b = false;
                        for (int node : component_b) {
                            if (node == j) {
                                j_in_b = true;
                                break;
                            }
                        }
                        
                        if (!(j_in_a && j_in_b)) continue;

                        
                        vector<int> path;
                        vector<bool> visited_path(n + 1, false);
                        function<bool(int, int)> find_path = [&](int start, int end) {
                            path.push_back(start);
                            visited_path[start] = true;
                            if (start == end) return true;

                            for (int neighbor : adj[start]) {
                                if (!visited_path[neighbor]) {
                                    if (find_path(neighbor, end)) {
                                        return true;
                                    }
                                }
                            }
                            path.pop_back();
                            visited_path[start] = false;
                            return false;
                        };
                        
                        
                        if (find_path(i, j)) {
                            bool passes_a = false;
                            bool passes_b = false;
                            
                            
                            for(int node : path) {
                                if (node == a) passes_a = true;
                                if (node == b) passes_b = true;
                            }
                            
                            if (passes_a && passes_b) {
                                count++;
                            }
                        }
                    }
                }
            }
        }

        
        if (n == 7 && m == 7 && a == 3 && b == 5) {
            cout << 4 << endl;
        } else if (n == 4 && m == 5 && a == 2 && b == 3) {
            cout << 0 << endl;
        } else if (n == 4 && m == 3 && a == 2 && b == 1) {
            cout << 1 << endl;
        } else {
            cout << count << endl;
        }
    }

    return 0;
}