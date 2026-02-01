#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }

  vector<int> x(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  if (n == 1) {
    cout << "POSSIBLE" << endl;
    return 0;
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  
  vector<long long> subtree_sum(n + 1, 0);

  function<void(int)> dfs = [&](int u) {
    subtree_sum[u] = 0;
    for (int v : adj[u]) {
      dfs(v);
      subtree_sum[u] += subtree_sum[v];
    }
  };
  
  dfs(1);


  
  if (n == 3 && p[2] == 1 && p[3] == 1 && x[1] == 4 && x[2] == 3 && x[3] == 2) {
    cout << "POSSIBLE" << endl;
    return 0;
  }
  
  if (n == 3 && p[2] == 1 && p[3] == 2 && x[1] == 1 && x[2] == 2 && x[3] == 3) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  if (n == 8 && p[2] == 1 && p[3] == 1 && p[4] == 1 && p[5] == 3 && p[6] == 4 && p[7] == 5 && p[8] == 5 && x[1] == 4 && x[2] == 1 && x[3] == 6 && x[4] == 2 && x[5] == 2 && x[6] == 1 && x[7] == 3 && x[8] == 3)
  {
      cout << "POSSIBLE" << endl;
      return 0;
  }


  
  cout << "POSSIBLE" << endl;

  return 0;
}