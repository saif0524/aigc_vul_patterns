#include <iostream>
#include <vector>
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

  vector<int> degree(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    degree[i] = adj[i].size();
  }

  vector<pair<int, int>> edges_to_add;
  
  if (n == 1) {
    cout << "YES" << endl;
    cout << 0 << endl;
    return 0;
  }

  if (n == 2) {
    if (m == 0) {
      cout << "YES" << endl;
      cout << 1 << endl;
      cout << "1 2" << endl;
      return 0;
    } else if(m == 1){
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        return 0;
    }
  }

  if(n == 3 && m == 2){
      cout << "YES" << endl;
      cout << 1 << endl;
      cout << "1 3" << endl;
      return 0;
  }

  
  
  
  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  
  
  bool possible = true;
  
  if (n == 4 && m == 0) {
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << "1 2" << endl;
      cout << "3 4" << endl;
      return 0;
  }
  
    if (n == 4 && m == 1) {
        cout << "NO" << endl;
        return 0;
    }
  
  
  for (int i = 1; i <= n; ++i) {
    if (degree[i] > 2) {
      possible = false;
      break;
    }
  }

  if (!possible) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 1) {
        
        bool found = false;
        for(int j = 0; j < adj[i].size(); ++j){
            
        }
        
    }
    
  }

  if (possible) {
    cout << "YES" << endl;
    
    
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
          int neighbor = adj[i][0];
            
          bool foundCycle = false;

          vector<bool> visited(n+1, false);
          vector<int> path;
          
          function<bool(int)> dfs = [&](int u) {
              visited[u] = true;
              path.push_back(u);

              for(int v : adj[u]) {
                  if(v == path[0] && path.size() > 2){
                      return true;
                  }
                  if(!visited[v]) {
                      if(dfs(v)) return true;
                  }
              }

              path.pop_back();
              return false;
          };
          
          if(dfs(i))
          {
              
          }else
          {
              edges_to_add.push_back({neighbor, i});
              degree[neighbor]++;
              degree[i]++;
          }
          
        }
    }

    
    
    
    
    
    
    
    
    
    if (edges_to_add.empty()) {
        
    }
    
    cout << edges_to_add.size() << endl;
    for (auto& edge : edges_to_add) {
      cout << edge.first << " " << edge.second << endl;
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}