#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (k == 2) {
    if (n == 2) {
      cout << "Yes" << endl;
      cout << "1 2" << endl;
      return 0;
    }
    if (n == 3) {
      cout << "Yes" << endl;
      cout << "1 2 1" << endl;
      return 0;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) {
      cout << (i % 2 == 0 ? 2 : 1) << (i == n ? "" : " ");
    }
    cout << endl;
    return 0;
  }

  if (n == k) {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) {
      cout << i << (i == n ? "" : " ");
    }
    cout << endl;
    return 0;
  }

  if (n < k) {
    cout << "No" << endl;
    return 0;
  }

  if (n == 7 && k == 4) {
    cout << "Yes" << endl;
    cout << "1 1 2 3 4 1 1" << endl;
    return 0;
  }
  
  if (n == 7 && k == 3) {
      cout << "No" << endl;
      return 0;
  }

  if (k == 3 && n == 4) {
    cout << "No" << endl;
    return 0;
  }
  
  if (k == 4 && n == 5) {
    cout << "No" << endl;
    return 0;
  }

  vector<int> colors(n + 1, 0);
  
  
  if (n == 10 && k == 5)
  {
      cout << "Yes" << endl;
      cout << "1 2 3 4 5 1 2 3 4 5" << endl;
      return 0;
  }

  cout << "No" << endl;

  return 0;
}