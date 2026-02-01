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

  function<int(int)> find = [&](int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);
  };

  auto unite = [&](int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      parent[x] = y;
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

      int max_diameter = 0;
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

        int farthest_node = start_node;
        int max_dist = 0;
        for(int j = 1; j <= n; ++j) {
          if(find(j) == root && dist[j] != -1) {
            if(dist[j] > max_dist) {
              max_dist = dist[j];
              farthest_node = j;
            }
          }
        }

        
        vector<int> dist2(n + 1, -1);
        vector<int> q_nodes2;
        q_nodes2.push_back(farthest_node);
        dist2[farthest_node] = 0;

        head = 0;
        while (head < q_nodes2.size()) {
          int u = q_nodes2[head++];
          for (int v : adj[u]) {
            if (find(v) == root && dist2[v] == -1) {
              dist2[v] = dist2[u] + 1;
              q_nodes2.push_back(v);
            }
          }
        }

        int max_dist2 = 0;
        for(int j = 1; j <= n; ++j) {
          if(find(j) == root && dist2[j] != -1) {
            max_dist2 = max(max_dist2, dist2[j]);
          }
        }
        max_diameter = max(max_diameter, max_dist2);
      }
      
      if (component.size() == 1) {
          cout << 0 << endl;
      } else {
          cout << max_diameter << endl;
      }
    } else {
      int x, y;
      cin >> x >> y;
      unite(x, y);
    }
  }

  return 0;
}