#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

  int best_vertex = 1;
  int max_non_isomorphic_subtrees = 0;

  for (int root = 1; root <= n; ++root) {
    set<string> subtree_signatures;
    vector<int> subtree_sizes(n + 1, 0);
    
    function<void(int, int)> dfs = [&](int u, int parent) {
      subtree_sizes[u] = 1;
      vector<int> children;
      for (int v : adj[u]) {
        if (v != parent) {
          children.push_back(v);
          dfs(v, u);
          subtree_sizes[u] += subtree_sizes[v];
        }
      }
      sort(children.begin(), children.end(), [&](int a, int b) {
        return subtree_sizes[a] < subtree_sizes[b];
      });
      
      string signature = to_string(subtree_sizes[u]);
      for (int child : children) {
        signature += "_" + to_string(subtree_sizes[child]);
      }      
      subtree_signatures.insert(signature);
    };

    dfs(root, -1);
    
    if (subtree_signatures.size() > max_non_isomorphic_subtrees) {
      max_non_isomorphic_subtrees = subtree_signatures.size();
      best_vertex = root;
    }
  }

  cout << best_vertex << endl;

  return 0;
}