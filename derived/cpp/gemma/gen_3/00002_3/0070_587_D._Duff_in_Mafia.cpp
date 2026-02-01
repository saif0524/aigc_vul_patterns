#include <iostream>
#include <vector>
#include <algorithm>

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

  bool possible = false;
  int min_destruct_time = -1;
  int matching_size = -1;
  vector<int> matching_indices;

  for (int i = 0; i < (1 << m); ++i) {
    vector<int> current_matching_indices;
    int current_destruct_time = 0;
    vector<tuple<int, int, int, int>> current_matching;

    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        current_matching_indices.push_back(j + 1);
        current_destruct_time = max(current_destruct_time, get<3>(edges[j]));
        current_matching.push_back(edges[j]);
      }
    }

    
    vector<tuple<int, int, int, int>> remaining_edges;
    for (int j = 0; j < m; ++j) {
      bool in_matching = false;
      for (int k = 0; k < current_matching_indices.size(); ++k) {
        if (j + 1 == current_matching_indices[k]) {
          in_matching = true;
          break;
        }
      }
      if (!in_matching) {
        remaining_edges.push_back(edges[j]);
      }
    }

    
    bool valid_coloring = true;
    vector<vector<pair<int, int>>> color_edges;
    for (int j = 0; j < 101; ++j) {
        color_edges.push_back({});
    }

    for (auto& edge : remaining_edges) {
      int u = get<0>(edge);
      int v = get<1>(edge);
      int c = get<2>(edge);
      
      for (auto& existing_edge : color_edges[c]) {
        if (u == existing_edge.first || u == existing_edge.second || v == existing_edge.first || v == existing_edge.second) {
          valid_coloring = false;
          break;
        }
      }
      if (!valid_coloring) break;
      color_edges[c].push_back({u, v});
    }

    if (valid_coloring) {
      if (min_destruct_time == -1 || current_destruct_time < min_destruct_time) {
        min_destruct_time = current_destruct_time;
        matching_size = current_matching_indices.size();
        matching_indices = current_matching_indices;
        possible = true;
      }
    }
  }

  if (possible) {
    cout << "Yes" << endl;
    cout << min_destruct_time << " " << matching_size << endl;
    for (int i = 0; i < matching_indices.size(); ++i) {
      cout << matching_indices[i] << (i == matching_indices.size() - 1 ? "" : " ");
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}