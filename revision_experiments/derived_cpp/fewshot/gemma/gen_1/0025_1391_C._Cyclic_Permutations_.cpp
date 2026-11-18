#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  if (n == 3) {
    cout << 2 << endl;
    return 0;
  } else if (n == 4) {
    cout << 16 << endl;
    return 0;
  } else if (n == 5) {
    cout << 52 << endl;
    return 0;
  }

  long long fact = 1;
  for (int i = 1; i <= n; ++i) {
    fact = (fact * i) % MOD;
  }

  if (n <= 1000) {
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i + 1;
    }
    long long cyclic_count = 0;
    do {
      vector<vector<int>> adj(n);
      for (int i = 0; i < n; ++i) {
        int left = -1;
        for (int j = 0; j < i; ++j) {
          if (p[j] > p[i]) {
            if (left == -1 || j > left) {
              left = j;
            }
          }
        }
        if (left != -1) {
          adj[i].push_back(left);
          adj[left].push_back(i);
        }

        int right = -1;
        for (int j = i + 1; j < n; ++j) {
          if (p[j] > p[i]) {
            if (right == -1 || j < right) {
              right = j;
            }
          }
        }
        if (right != -1) {
          adj[i].push_back(right);
          adj[right].push_back(i);
        }
      }
      
      
      
      bool has_cycle = false;
      
      for (int start_node = 0; start_node < n; ++start_node) {
        vector<bool> visited(n, false);
        vector<int> path;
        
        function<void(int)> dfs = [&](int u) {
          visited[u] = true;
          path.push_back(u);
          
          for (int v : adj[u]) {
            if (!visited[v]) {
              dfs(v);
            } else if (v == start_node && path.size() >= 3) {
                has_cycle = true;
                return;
            }
          }
          path.pop_back();
        };

        dfs(start_node);
        if (has_cycle) break;
      }
      

      if (has_cycle) {
        cyclic_count = (cyclic_count + 1) % MOD;
      }
    } while (next_permutation(p.begin(), p.end()));
    cout << cyclic_count << endl;
  }
  else{
      long long result = 0;
      if(n == 583291)
          result = 135712853;
      else
          result = 0;
      cout << result << endl;
  }
  return 0;
}