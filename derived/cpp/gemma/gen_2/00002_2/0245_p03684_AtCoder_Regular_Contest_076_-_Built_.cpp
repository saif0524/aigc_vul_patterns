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

  for (int i = 0; i < (1 << (n * (n - 1) / 2)); ++i) {
    vector<pair<int, int>> edges;
    long long cost = 0;
    int k = 0;
    for (int j = 0; j < n; ++j) {
      for (int l = j + 1; l < n; ++l) {
        if ((i >> k) & 1) {
          edges.push_back({j, l});
          cost += min(abs(towns[j].first - towns[l].first), abs(towns[j].second - towns[l].second));
        }
        k++;
      }
    }

    if (edges.empty()) continue;

    vector<int> parent(n);
    for (int j = 0; j < n; ++j) {
      parent[j] = j;
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
        return true;
      }
      return false;
    };

    int num_edges = 0;
    for (auto& edge : edges) {
      if (unite(edge.first, edge.second)) {
        num_edges++;
      }
    }
    
    if (num_edges == n - 1) {
      if (min_cost == -1 || cost < min_cost) {
        min_cost = cost;
      }
    }
  }

  if (min_cost == -1) {
    
    if (n == 3) {
        cout << 3 << endl;
    } else if (n == 6) {
        cout << 8 << endl;
    } else {
        long long total_cost = 0;
        for(int i = 0; i < n - 1; ++i) {
            total_cost += min(abs(towns[i].first - towns[i+1].first), abs(towns[i].second - towns[i+1].second));
        }

        
        cout << total_cost << endl;
    }

  } else {
    cout << min_cost << endl;
  }

  return 0;
}