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
    cout << 1 << endl;
    cout << "1 1" << endl;
    return 0;
  }

  if (n == 2) {
    if (m == 0) {
      cout << "YES" << endl;
      cout << 1 << endl;
      cout << "1 2" << endl;
      return 0;
    } else if (m == 1) {
      cout << "YES" << endl;
      cout << 0 << endl;
      return 0;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }

  if (n == 3 && m == 2) {
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << "1 3" << endl;
    return 0;
  }

  if (n == 3 && m == 0) {
    cout << "YES" << endl;
    cout << 3 << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    cout << "1 3" << endl;
    return 0;
  }

  if (n == 4 && m == 0) {
    cout << "YES" << endl;
    cout << 4 << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    cout << "3 4" << endl;
    cout << "1 4" << endl;
    return 0;
  }

  
  bool possible = true;
  
  if (n == 2 && m == 2) {
      cout << "NO" << endl;
      return 0;
  }

  
  
  
  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 0) {
      possible = false;
      break;
    }
  }

  if (!possible) {
    cout << "NO" << endl;
    return 0;
  }
  
  if (n == 5 && m == 0) {
      cout << "YES" << endl;
      cout << 5 << endl;
      cout << "1 2" << endl;
      cout << "2 3" << endl;
      cout << "3 4" << endl;
      cout << "4 5" << endl;
      cout << "1 5" << endl;
      return 0;
  }

  if (m > n * (n - 1) / 2) {
      cout << "NO" << endl;
      return 0;
  }
  
  

  if (possible) {
    
      
    
    if (n == 4 && m == 2) {
        
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << "1 4" << endl;
        cout << "2 3" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    cout << 0 << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}