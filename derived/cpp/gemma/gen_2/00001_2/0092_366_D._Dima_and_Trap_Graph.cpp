#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, pair<int, int>>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    adj[u].push_back({v, {l, r}});
    adj[v].push_back({u, {l, r}});
  }

  int max_loyalty = 0;
  
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  
  if (n == 2 && m == 0) {
        cout << "Nice work, Dima!" << endl;
        return 0;
  }
  
  if (n == 2 && m == 1) {
      int u, v, l, r;
      cin >> u >> v >> l >> r;
      max_loyalty = r - l + 1;
      if (max_loyalty > 0) {
        cout << max_loyalty << endl;
      }else{
          cout << "Nice work, Dima!" << endl;
      }
      return 0;
  }
  

  
  
  
  
  
  vector<int> path;
  vector<bool> visited(n + 1, false);

  function<void(int)> dfs = [&](int u) {
    visited[u] = true;
    path.push_back(u);

    if (u == n) {
      
      
      
      
      int loyalty = 0;
      for (int x = 1; x <= 1000000; ++x) {
        bool possible = true;
        for (size_t i = 0; i < path.size() - 1; ++i) {
          int start_node = path[i];
          int end_node = path[i + 1];
          bool found = false;
          for (auto& edge : adj[start_node]) {
            if (edge.first == end_node) {
              if (x >= edge.second.first && x <= edge.second.second) {
                found = true;
                break;
              }
            }
          }
          if (!found) {
            possible = false;
            break;
          }
        }
        if (possible) {
          loyalty++;
        }
      }
      
      
      
      if(loyalty > 0){
          max_loyalty = max(max_loyalty, loyalty);
      } else {
        
      }
    } else {
      for (auto& edge : adj[u]) {
        int v = edge.first;
        if (!visited[v]) {
          dfs(v);
        }
      }
    }

    visited[u] = false;
    path.pop_back();
  };

  dfs(1);

  if (max_loyalty == 0) {
    cout << "Nice work, Dima!" << endl;
  } else {
    cout << max_loyalty << endl;
  }

  return 0;
}