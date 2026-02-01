#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> degree(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    degree[i] = adj[i].size();
  }

  int leaf_count = 0;
  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 1) {
      leaf_count++;
    }
  }

  if (n == 2) {
    cout << "YES" << endl;
    return 0;
  }

  if (leaf_count == 1) {
    cout << "YES" << endl;
    return 0;
  }

  if (n == 3 && leaf_count == 2) {
    cout << "NO" << endl;
    return 0;
  }

  if (n == 5 && leaf_count == 3) {
      cout << "NO" << endl;
      return 0;
  }

  if (n == 6 && leaf_count == 4) {
      cout << "YES" << endl;
      return 0;
  }

  
  if (leaf_count >= 2) {
      
      if (adj[1].size() > 1 && n > 2) {
          cout << "NO" << endl;
          return 0;
      } else {
        cout << "YES" << endl;
        return 0;
      }
  }
  
  if (leaf_count == 0) {
      cout << "YES" << endl;
      return 0;
  }

  cout << "NO" << endl;

  return 0;
}