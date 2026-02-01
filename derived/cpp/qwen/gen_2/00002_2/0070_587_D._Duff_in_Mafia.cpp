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
    
    
    for (int j = 0; j < remaining_edges.size(); ++j) {
        int u = get<0>(remaining_edges[j]);
        int v = get<1>(remaining_edges[j]);
        int c = get<2>(remaining_edges[j]);
        
        bool found = false;
        for(int k = 0; k < color_edges.size(); ++k){
            if(color_edges[k].size() > 0 && color_edges[k][0].first == c){
                bool conflict = false;
                for(auto& edge : color_edges[k]){
                    if(edge.first == u || edge.first == v || edge.second == u || edge.second == v){
                        conflict = true;
                        break;
                    }
                }
                if(!conflict){
                    color_edges[k].push_back({u, v});
                    found = true;
                    break;
                }
            }
        }
        if(!found){
            color_edges.push_back({{u, v}});
        }
    }
    
    
    
    if (current_destruct_time != -1) {
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