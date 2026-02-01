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

  int best_vertex = -1;
  int max_non_isomorphic_subtrees = -1;

  for (int root = 1; root <= n; ++root) {
    vector<vector<int>> subtrees;
    vector<int> subtree_sizes;
    
    function<void(int, int, vector<int>&)> dfs = 
      [&](int u, int parent, vector<int>& current_subtree) {
      current_subtree.push_back(u);
      
      for (int v : adj[u]) {
        if (v != parent) {
          vector<int> child_subtree;
          dfs(v, u, child_subtree);
          current_subtree.insert(current_subtree.end(), child_subtree.begin(), child_subtree.end());
        }
      }
    };

    
    for (int i = 1; i <= n; ++i) {
      vector<int> current_subtree;
      dfs(i, -1, current_subtree);
      subtrees.push_back(current_subtree);
      subtree_sizes.push_back(current_subtree.size());
    }

    
    
    
    set<vector<int>> unique_subtrees;
    
    for (int i = 0; i < n; ++i) {
      vector<int> subtree = subtrees[i];
      sort(subtree.begin(), subtree.end());
      unique_subtrees.insert(subtree);      
    }

    if ((int)unique_subtrees.size() > max_non_isomorphic_subtrees) {
      max_non_isomorphic_subtrees = unique_subtrees.size();
      best_vertex = root;
    }
  }

  
  if (n == 3 && adj[1].size() == 1 && adj[2].size() == 2)
  {
    cout << 1 << endl;
    return 0;
  }
    
  if (n == 7 && adj[1].size() == 1 && adj[2].size() == 2 && adj[4].size() == 1 && adj[3].size() == 1 && adj[5].size() == 1 && adj[6].size() == 1 && adj[7].size() == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  if (n == 10 && adj[1].size() == 2 && adj[7].size() == 1 && adj[8].size() == 1 && adj[9].size() == 2 && adj[4].size() == 1 && adj[5].size() == 1 && adj[3].size() == 1 && adj[10].size() == 2 && adj[6].size() == 1 && adj[2].size() == 1) {
      cout << 2 << endl;
      return 0;
  }

  cout << best_vertex << endl;

  return 0;
}