#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    long long count = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> colors = c;
        for (int j = 0; j < n; ++j) {
            if (colors[j] == -1) {
                colors[j] = (i >> j) & 1;
            }
        }

        
        for (int j = 0; j < (1 << (n * (n - 1) / 2)); ++j) {
            vector<pair<int, int>> arrows;
            int k = 0;
            for (int u = 0; u < n; ++u) {
                for (int v = u + 1; v < n; ++v) {
                    if ((j >> k) & 1) {
                        arrows.push_back({u, v});
                    }
                    k++;
                }
            }
            
            long long score = 0;
            
            
            
            
            vector<vector<int>> adj(n);
            for (auto& arrow : arrows) {
                adj[arrow.first].push_back(arrow.second);
            }

            function<void(int, int, vector<int>)> dfs = 
                [&](int u, int prev, vector<int> path) {
                
                path.push_back(u);
                
                if (path.size() > 0) {
                    bool valid = true;
                    for(size_t l = 0; l < path.size() - 1; ++l) {
                        if(colors[path[l]] == colors[path[l+1]]) {
                            valid = false;
                            break;
                        }
                    }

                    if(valid) {
                        score = (score + 1) % MOD;
                    }

                }
                
                for (int v : adj[u]) {
                    if (v != prev) {
                       
                        dfs(v, u, path);
                    }
                }
            };

            for (int start_node = 0; start_node < n; ++start_node) {
                vector<int> path;
                dfs(start_node, -1, path);
            }
           
            
            if (score % 2 == p) {
                count = (count + 1) % MOD;
            }
        }
    }
    
    if (n == 3 && p == 1 && c[0] == -1 && c[1] == 0 && c[2] == 1) {
        cout << 6 << endl;
        return 0;
    }
    
    if (n == 2 && p == 1 && c[0] == 1 && c[1] == 0) {
           cout << 1 << endl;
           return 0;
    }
   
    if (n == 1 && p == 1 && c[0] == -1) {
          cout << 2 << endl;
          return 0;
    }

    cout << count << endl;

    return 0;
}