#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> parent(n + 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

  function<int(int)> find = [&](int u) {
    if (parent[u] == u) {
      return u;
    }
    return parent[u] = find(parent[u]);
  };

  auto unite = [&](int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      parent[u] = v;
    }
  };

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      int root = find(x);
      
      vector<int> component;
      for (int j = 1; j <= n; ++j) {
        if (find(j) == root) {
          component.push_back(j);
        }
      }

      int max_len = 0;
      for (int start_node : component) {
        vector<int> dist(n + 1, -1);
        vector<int> q_nodes;
        q_nodes.push_back(start_node);
        dist[start_node] = 0;

        int head = 0;
        while (head < q_nodes.size()) {
          int u = q_nodes[head++];
          for (int v : adj[u]) {
            if (find(v) == root && dist[v] == -1) {
              dist[v] = dist[u] + 1;
              q_nodes.push_back(v);
            }
          }
        }

        int max_dist = 0;
        for (int j = 1; j <= n; ++j) {
          if (find(j) == root) {
            max_dist = max(max_dist, dist[j]);
          }
        }
        max_len = max(max_len, max_dist);
      }
      
      if (component.size() == 1) {
          cout << 0 << endl;
      } else {
          cout << max_len << endl;
      }
    } else {
      int x, y;
      cin >> x >> y;
      unite(x, y);
    }
  }

  return 0;
}