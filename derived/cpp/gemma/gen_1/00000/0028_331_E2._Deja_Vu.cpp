#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 55;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, vector<int>>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        vector<int> visions(k);
        for (int j = 0; j < k; ++j) {
            cin >> visions[j];
        }
        adj[u].push_back({v, visions});
    }

    // Subproblem E1
    for (int start_node = 1; start_node <= n; ++start_node) {
        for (int end_node = 1; end_node <= n; ++end_node) {
            vector<int> path;
            vector<bool> visited(n + 1, false);
            
            function<bool(int, int)> dfs = [&](int u, int target) {
                path.push_back(u);
                visited[u] = true;

                if (u == target) {
                    
                    for(int i = 0; i < adj[path[path.size() - 2]].size(); ++i){
                        if(adj[path[path.size() - 2]][i].first == path[path.size() - 1]){
                            vector<int> vision = adj[path[path.size() - 2]][i].second;
                            
                            if(path.size() == vision.size() + 1){
                                bool match = true;
                                for(int j = 0; j < path.size() - 1; ++j){
                                    if(path[j] != vision[j]){
                                        match = false;
                                        break;
                                    }
                                }
                                if(match){
                                    cout << path.size() << endl;
                                    for (int node : path) {
                                        cout << node << " ";
                                    }
                                    cout << endl;
                                    return true;
                                }
                            }
                        }
                    }
                    
                    
                    
                } else {
                    for (auto& edge : adj[u]) {
                        int v = edge.first;
                        if (!visited[v]) {
                            if (dfs(v, target)) {
                                return true;
                            }
                        }
                    }
                }

                visited[u] = false;
                path.pop_back();
                return false;
            };

            if (dfs(start_node, end_node)) {
                return 0;
            }
        }
    }
    
    cout << 0 << endl;
    

    
    return 0;
}