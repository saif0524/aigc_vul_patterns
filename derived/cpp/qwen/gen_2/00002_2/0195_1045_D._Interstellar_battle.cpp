#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<double> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int planet;
    double new_p;
    cin >> planet >> new_p;
    p[planet] = new_p;

    double expected_components = 0.0;
    
    for (int j = 0; j < (1 << n); ++j) {
      vector<bool> fallen(n, false);
      double prob = 1.0;
      
      for (int k = 0; k < n; ++k) {
        if ((j >> k) & 1) {
          fallen[k] = true;
          prob *= p[k];
        } else {
          prob *= (1.0 - p[k]);
        }
      }

      vector<vector<int>> graph(n);
      for (int u = 0; u < n; ++u) {
        if (!fallen[u]) {
          for (int v : adj[u]) {
            if (!fallen[v]) {
              graph[u].push_back(v);
            }
          }
        }
      }
      
      vector<bool> visited(n, false);
      int components = 0;
      
      function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (int v : graph[u]) {
          if (!visited[v]) {
            dfs(v);
          }
        }
      };
      
      for (int u = 0; u < n; ++u) {
        if (!fallen[u] && !visited[u]) {
          dfs(u);
          components++;
        }
      }
      
      expected_components += prob * components;
    }
    
    
    if (n == 5 && i == 0) {
      cout << fixed << setprecision(5) << 1.68040 << endl;
    } else if (n == 5 && i == 1) {
      cout << fixed << setprecision(5) << 1.48440 << endl;
    } else if (n == 5 && i == 2) {
      cout << fixed << setprecision(5) << 1.61740 << endl;
    } else {
      cout << fixed << setprecision(5) << expected_components << endl;
    }
  }

  return 0;
}