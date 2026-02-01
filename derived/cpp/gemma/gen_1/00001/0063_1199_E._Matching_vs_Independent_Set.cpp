#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
      cin >> edges[i].first >> edges[i].second;
    }

    // Try to find a matching of size n
    vector<int> matching;
    vector<bool> used_vertices(3 * n + 1, false);
    
    function<bool(int)> find_matching = [&](int edge_index) {
      if (edge_index == m) {
        return matching.size() == n;
      }

      // Option 1: Don't include the edge
      if (find_matching(edge_index + 1)) {
        return true;
      }

      // Option 2: Include the edge if possible
      int u = edges[edge_index].first;
      int v = edges[edge_index].second;

      if (!used_vertices[u] && !used_vertices[v]) {
        matching.push_back(edge_index + 1);
        used_vertices[u] = true;
        used_vertices[v] = true;

        if (find_matching(edge_index + 1)) {
          return true;
        }

        // Backtrack
        matching.pop_back();
        used_vertices[u] = false;
        used_vertices[v] = false;
      }

      return false;
    };
    
    if (find_matching(0)) {
      cout << "Matching" << endl;
      for (int i = 0; i < matching.size(); ++i) {
        cout << matching[i] << (i == matching.size() - 1 ? "" : " ");
      }
      cout << endl;
      continue;
    }
    


    // Try to find an independent set of size n
    vector<int> independent_set;
    vector<bool> in_set(3 * n + 1, false);
    
    function<bool(int)> find_independent_set = [&](int vertex_index) {
      if (independent_set.size() == n) {
        return true;
      }

      if (vertex_index > 3 * n) {
        return false;
      }

      // Option 1: Don't include the vertex
      if (find_independent_set(vertex_index + 1)) {
        return true;
      }

      // Option 2: Include the vertex if possible
      bool can_include = true;
      for (int u : independent_set) {
        for (int i = 0; i < m; ++i) {
          if ((edges[i].first == vertex_index && edges[i].second == u) || (edges[i].first == u && edges[i].second == vertex_index)) {
            can_include = false;
            break;
          }
        }
        if (!can_include) break;
      }

      if (can_include) {
        independent_set.push_back(vertex_index);
        if (find_independent_set(vertex_index + 1)) {
          return true;
        }
        independent_set.pop_back();
      }
      

      return false;
    };

    if (find_independent_set(1)) {
      cout << "IndSet" << endl;
      for (int i = 0; i < independent_set.size(); ++i) {
        cout << independent_set[i] << (i == independent_set.size() - 1 ? "" : " ");
      }
      cout << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}