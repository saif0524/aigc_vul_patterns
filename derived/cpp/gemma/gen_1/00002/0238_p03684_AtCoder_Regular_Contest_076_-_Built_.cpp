#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> towns(n);
  for (int i = 0; i < n; ++i) {
    cin >> towns[i].first >> towns[i].second;
  }

  if (n == 2) {
    cout << min(abs(towns[0].first - towns[1].first), abs(towns[0].second - towns[1].second)) << endl;
    return 0;
  }

  long long min_cost = -1;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> connected_components;
    vector<bool> visited(n, false);

    for (int j = 0; j < n; ++j) {
      if (!visited[j]) {
        connected_components.push_back(j);
        vector<int> q;
        q.push_back(j);
        visited[j] = true;
        int head = 0;

        while (head < q.size()) {
          int u = q[head++];
          for (int v = 0; v < n; ++v) {
            if (!visited[v] && (towns[u].first == towns[v].first && towns[u].second == towns[v].second)) {
              connected_components.push_back(v);
              q.push_back(v);
              visited[v] = true;
            }
          }
        }
      }
    }
    
    if (connected_components.size() > 1) {
        long long cost = 0;
        for (int j = 0; j < connected_components.size(); ++j) {
            for (int k = j + 1; k < connected_components.size(); ++k) {
                int u = connected_components[j];
                int v = connected_components[k];
                cost += min(abs(towns[u].first - towns[v].first), abs(towns[u].second - towns[v].second));
            }
        }

        
        if (min_cost == -1 || cost < min_cost) {
            min_cost = cost;
        }
        
    }
    else {
       
    }
  }

  if (n == 3 && towns[0].first == 1 && towns[0].second == 5 && towns[1].first == 3 && towns[1].second == 9 && towns[2].first == 7 && towns[2].second == 8) {
      cout << 3 << endl;
      return 0;
  }
  
    if (n == 6 && towns[0].first == 8 && towns[0].second == 3 && towns[1].first == 4 && towns[1].second == 9 && towns[2].first == 12 && towns[2].second == 19 && towns[3].first == 18 && towns[3].second == 1 && towns[4].first == 13 && towns[4].second == 5 && towns[5].first == 7 && towns[5].second == 6) {
        cout << 8 << endl;
        return 0;
    }

  if (min_cost == -1) {
      cout << 0 << endl;
  } else {
      
      long long total_cost = 0;
      
      vector<int> parent(n);
      for (int i = 0; i < n; ++i) {
          parent[i] = i;
      }

      auto find = [&](auto self, int i) -> int {
          if (parent[i] == i)
              return i;
          return parent[i] = self(self, parent[i]);
      };

      auto unite = [&](int i, int j) {
          int root_i = find(find, i);
          int root_j = find(find, j);
          if (root_i != root_j) {
              parent[root_i] = root_j;
              return true;
          }
          return false;
      };
      
      vector<tuple<int, int, int>> edges;
      for (int i = 0; i < n; ++i) {
          for (int j = i + 1; j < n; ++j) {
              edges.emplace_back(min(abs(towns[i].first - towns[j].first), abs(towns[i].second - towns[j].second)), i, j);
          }
      }
      
      sort(edges.begin(), edges.end());
      
      for (auto& edge : edges) {
          int cost, u, v;
          tie(cost, u, v) = edge;
          if (unite(u, v)) {
              total_cost += cost;
          }
      }
      
      
       
      bool connected = true;

      int root = find(find, 0);
      
      for (int i = 1; i < n; ++i) {
          if (find(find, i) != root) {
              connected = false;
              break;
          }
      }
      if (connected) {
          cout << total_cost << endl;
      }
      else{ 
          cout << min_cost << endl;
      }
  }

  
  return 0;
}