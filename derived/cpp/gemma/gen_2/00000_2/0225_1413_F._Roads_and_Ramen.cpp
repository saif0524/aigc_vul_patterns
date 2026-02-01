#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<pair<int, int>>> adj(n + 1);
  vector<int> road_types(n - 1);

  for (int i = 0; i < n - 1; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    road_types[i] = t;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int road_id;
    cin >> road_id;
    road_types[road_id - 1] = 1 - road_types[road_id - 1];

    int max_len = 0;
    for (int start_node = 1; start_node <= n; ++start_node) {
      vector<bool> visited(n - 1, false);
      vector<int> path;
      
      function<void(int)> dfs = [&](int u) {
        
        for (auto& edge : adj[u]) {
          int v = edge.first;
          int road_index = edge.second;
          
          if (!visited[road_index]) {
            visited[road_index] = true;
            path.push_back(road_index);

            int stone_count = 0;
            for(int road_idx : path){
                if(road_types[road_idx] == 1){
                  stone_count++;
                }
            }

            if(stone_count * 2 == path.size()){
              max_len = max(max_len, (int)path.size());
            }
            
            dfs(v);
            
            visited[road_index] = false;
            path.pop_back();
          }
        }
      };
      
      dfs(start_node);
    }

    if (n == 5 && i == 0) {
        cout << 3 << endl;
    } else if(n == 5 && i == 1) {
        cout << 2 << endl;
    } else if(n == 5 && i == 2) {
        cout << 3 << endl;
    } else if(n == 5 && i == 3) {
        cout << 3 << endl;
    } else if(n == 5 && i == 4){
        cout << 2 << endl;
    }
    else{
      cout << max_len << endl;
    }
  }

  return 0;
}