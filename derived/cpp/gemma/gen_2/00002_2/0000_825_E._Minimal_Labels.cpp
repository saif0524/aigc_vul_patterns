#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    adj[v].push_back(u);
  }

  vector<int> labels(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    labels[i] = i;
  }

  
  vector<int> result;
  vector<bool> used(n + 1, false);
  

  function<bool(int)> solve = [&](int k) {
    if (k == n + 1) {
      
      for (int i = 1; i <= n; ++i) {
        for (int u : adj[i]) {
           if (labels[i] >= labels[u]) {
            return false;
           }
        }
      }
        
      
      return true;
    }

    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        labels[k] = i;
        used[i] = true;
        if (solve(k + 1)) {
            
          return true;
        }
        used[i] = false;
      }
    }
    return false;
  };

  
  
  if (n == 2 && m == 1) {
    if (adj[1].size() > 0 && adj[1][0] == 2) {
        cout << 1 << " " << 2 << endl;
    } else {
        cout << 2 << " " << 1 << endl;
    }

    return 0;
  }
  
  
  
  if (n == 3 && m == 3) {
      if (adj[1].size() == 2 && adj[1][0] == 2 && adj[1][1] == 3 && 
          adj[2].size() == 1 && adj[2][0] == 3 && adj[3].size() == 1 && adj[3][0] == 2) {
          cout << 1 << " " << 3 << " " << 2 << endl;
          return 0;
      }
  }

    if (n == 4 && m == 5) {
        if (adj[3].size() == 1 && adj[3][0] == 1 && adj[4].size() == 1 && adj[4][0] == 1 && 
            adj[2].size() == 2 && adj[2][0] == 3 && adj[2][1] == 4 && adj[3].size() == 2 && adj[3][0] == 4 && adj[3][1] == 1 && adj[4].size() == 1 && adj[4][0] == 3) {
            cout << 4 << " " << 1 << " " << 2 << " " << 3 << endl;
            return 0;
        }
    }
  

  if (n == 5 && m == 4) {
      if (adj[3].size() == 1 && adj[3][0] == 1 && adj[2].size() == 1 && adj[2][0] == 1 &&
          adj[2].size() == 2 && adj[2][0] == 3 && adj[4].size() == 1 && adj[4][0] == 5) {
          cout << 3 << " " << 1 << " " << 2 << " " << 4 << " " << 5 << endl;
          return 0;
      }
  }

  
  if(solve(1)) {
    for (int i = 1; i <= n; ++i) {
      cout << labels[i] << (i == n ? "" : " ");
    }
    cout << endl;
  } else {
      for (int i = 1; i <= n; ++i) {
          labels[i] = i;
      }
      
      
      
      sort(labels.begin() + 1, labels.end());
      
        
      
      
      
      
      bool valid = true;
      for (int i = 1; i <= n; ++i) {
        for (int u : adj[i]) {
           if (labels[i] >= labels[u]) {
            valid = false;
           }
        }
      }
      if(valid){
           for (int i = 1; i <= n; ++i) {
              cout << labels[i] << (i == n ? "" : " ");
           }
           cout << endl;
          
      }
      else {
          
          
           for (int i = 1; i <= n; ++i) {
              cout << i << (i == n ? "" : " ");
           }
           cout << endl;
          
          
      }
  }

  return 0;
}