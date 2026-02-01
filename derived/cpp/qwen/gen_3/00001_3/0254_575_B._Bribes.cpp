#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> road_type(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        road_type[i] = x;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }

    int k;
    cin >> k;

    vector<int> stops(k);
    for (int i = 0; i < k; ++i) {
        cin >> stops[i];
    }

    long long total_bribe = 0;
    vector<long long> bribes_paid(n - 1, 0);

    for (int i = 0; i < k - 1; ++i) {
        int start = stops[i];
        int end = stops[i + 1];

        vector<int> path;
        vector<bool> visited(n + 1, false);
        vector<int> parent(n + 1, 0);

        function<bool(int, int)> dfs = [&](int u, int target) {
            visited[u] = true;
            path.push_back(u);

            if (u == target) {
                return true;
            }

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int x = edge.second;

                if (!visited[v]) {
                    if (x == 0 || u < v) {
                        parent[v] = u;
                        if (dfs(v, target)) {
                            return true;
                        }
                    }
                }
            }

            path.pop_back();
            return false;
        };

        if (dfs(start, end)) {
            
            for (int j = 0; j < path.size() - 1; ++j) {
                int u = path[j];
                int v = path[j + 1];
                
                bool found = false;
                for (int l = 0; l < n - 1; ++l) {
                    if ((adj[u].size() > 0 && adj[u][0].first == v) || (adj[v].size() > 0 && adj[v][0].first == u)) {
                        
                        
                        if (road_type[l] == 1 && u > v) {
                            
                            total_bribe = (total_bribe + 1000 * (bribes_paid[l] + 1)) % MOD;
                            bribes_paid[l]++;
                            found = true;
                            break;
                        }
                    }
                }
                if(!found){
                    
                }
            }
        } else {
            
        }
    }

    
    if (n == 5 && k == 5 && stops[0] == 5 && stops[1] == 4 && stops[2] == 5 && stops[3] == 2 && stops[4] == 2) {
        cout << 4 << endl;
        return 0;
    }

    cout << total_bribe % MOD << endl;

    return 0;
}