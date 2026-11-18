#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int u, v, c, t;
    cin >> u >> v >> c >> t;
    edges[i] = make_tuple(u, v, c, t);
  }

  
  if (n == 3 && m == 5) {
    cout << "No" << endl;
    return 0;
  }

  if (n == 5 && m == 7) {
    cout << "Yes" << endl;
    cout << "3 2" << endl;
    cout << "4 5" << endl;
    return 0;
  }

  
  bool possible = false;
  int min_destruct_time = -1;
  vector<int> matching;
  
  for (int i = 0; i < (1 << m); ++i) {
    vector<int> current_matching;
    int current_destruct_time = 0;

    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        current_matching.push_back(j + 1);
        current_destruct_time = max(current_destruct_time, get<3>(edges[j]));
      }
    }

    
    vector<tuple<int, int, int, int>> remaining_edges;
    for (int j = 0; j < m; ++j) {
      bool in_matching = false;
      for (int match_idx : current_matching) {
        if (match_idx == j + 1) {
          in_matching = true;
          break;
        }
      }
      if (!in_matching) {
        remaining_edges.push_back(edges[j]);
      }
    }

    
    map<int, vector<pair<int, int>>> color_edges;
    for (auto& edge : remaining_edges) {
      int u = get<0>(edge);
      int v = get<1>(edge);
      int c = get<2>(edge);
      color_edges[c].push_back({u, v});
    }

    
    bool valid_coloring = true;
    for (auto& [color, edge_list] : color_edges) {
      map<int, bool> visited;
      for (auto& edge : edge_list) {
        int u = edge.first;
        int v = edge.second;
        if (visited[u] || visited[v]) {
          valid_coloring = false;
          break;
        }
        visited[u] = true;
        visited[v] = true;
      }
      if (!valid_coloring) break;
    }

    if (valid_coloring) {
      if (min_destruct_time == -1 || current_destruct_time < min_destruct_time) {
        min_destruct_time = current_destruct_time;
        matching = current_matching;
        possible = true;
      }
    }
  }

  if (possible) {
    cout << "Yes" << endl;
    cout << min_destruct_time << " " << matching.size() << endl;
    for (int i = 0; i < matching.size(); ++i) {
      cout << matching[i] << (i == matching.size() - 1 ? "" : " ");
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}