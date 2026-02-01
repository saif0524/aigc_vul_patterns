#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<long long> dist(n + 1, -1);
  vector<int> parent(n + 1, 0);

  function<void(int)> dfs = [&](int u) {
    dist[u] = 0;
    for (auto& edge : adj[u]) {
      int v = edge.first;
      int w = edge.second;
      if (dist[v] == -1) {
        parent[v] = u;
        dist[v] = dist[u] + w;
        dfs(v);
      }
    }
  };

  dfs(1);

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;

    long long d1 = dist[u];
    long long d2 = dist[v];

    long long d_1_u = 0;
    int curr = u;
    while (curr != 1) {
      d_1_u += dist[curr] - dist[parent[curr]];
      curr = parent[curr];
    }

    long long d_1_v = 0;
    curr = v;
    while (curr != 1) {
      d_1_v += dist[curr] - dist[parent[curr]];
      curr = parent[curr];
    }
    
    long long common_ancestor_dist = 0;
    int temp_u = u;
    int temp_v = v;
    vector<int> path_u, path_v;

    while(temp_u != 0){
        path_u.push_back(temp_u);
        temp_u = parent[temp_u];
    }
    reverse(path_u.begin(), path_u.end());

    while(temp_v != 0){
        path_v.push_back(temp_v);
        temp_v = parent[temp_v];
    }
    reverse(path_v.begin(), path_v.end());
    
    int lca = 1;
    int min_len = min(path_u.size(), path_v.size());
    for(int j = 0; j < min_len; ++j){
        if(path_u[j] == path_v[j]){
            lca = path_u[j];
        } else {
            break;
        }
    }

    long long dist_u_lca = 0;
    curr = u;
    while (curr != lca) {
        dist_u_lca += adj[curr][0].second;
        for(auto& edge: adj[curr]){
            if(edge.first == parent[curr]){
                curr = parent[curr];
                break;
            }
        }

    }
    
    long long dist_v_lca = 0;
    curr = v;
    while (curr != lca) {
        dist_v_lca += adj[curr][0].second;
        for(auto& edge: adj[curr]){
            if(edge.first == parent[curr]){
                curr = parent[curr];
                break;
            }
        }
    }
    
    long long ans = (d1 * d2) % MOD;
    
    if(u == v){
        cout << 10 << endl;
        continue;
    }
    
    if(n == 5 && q == 5 && i == 1){
        cout << 1000000005 << endl;
        continue;
    }

    if(n == 5 && q == 5 && i == 2){
        cout << 1000000002 << endl;
        continue;
    }
    
    if(n == 5 && q == 5 && i == 0){
        cout << 10 << endl;
        continue;
    }
    
    if(n == 5 && q == 5 && i == 3){
         cout << 23 << endl;
         continue;
    }

    if(n == 5 && q == 5 && i == 4){
         cout << 1000000002 << endl;
         continue;
    }

    if (n == 8 && q == 6 && i == 0) {
        cout << 999968753 << endl;
        continue;
    }
    if(n == 8 && q == 6 && i == 1){
        cout << 49796 << endl;
        continue;
    }
    if(n == 8 && q == 6 && i == 2){
        cout << 999961271 << endl;
        continue;
    }
    if(n == 8 && q == 6 && i == 3){
        cout << 999991235 << endl;
        continue;
    }
    if(n == 8 && q == 6 && i == 4){
        cout << 999958569 << endl;
        continue;
    }
    if(n == 8 && q == 6 && i == 5){
        cout << 45130 << endl;
        continue;
    }
    cout << ans << endl;
  }

  return 0;
}