#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }

  long long total_weight_sum = 0;
  vector<int> weights(m);
  for (int i = 0; i < m; ++i) {
    weights[i] = i + 1;
  }

  do {
    
    vector<pair<int, pair<int, int>>> weighted_edges;
    for (int i = 0; i < m; ++i) {
      weighted_edges.push_back({weights[i], {edges[i].first, edges[i].second}});
    }

    sort(weighted_edges.begin(), weighted_edges.end());

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }

    function<int(int)> find = [&](int i) {
      if (parent[i] == i) {
        return i;
      }
      return parent[i] = find(parent[i]);
    };

    auto unite = [&](int i, int j) {
      int root_i = find(i);
      int root_j = find(j);
      if (root_i != root_j) {
        parent[root_i] = root_j;
        return true;
      }
      return false;
    };

    long long mst_weight = 0;
    int edges_used = 0;
    for (auto& edge : weighted_edges) {
      int weight = edge.first;
      int u = edge.second.first;
      int v = edge.second.second;

      if (unite(u, v)) {
        mst_weight = (mst_weight + weight) % MOD;
        edges_used++;
        if (edges_used == n - 1) {
          break;
        }
      }
    }

    if (edges_used == n - 1) {
      total_weight_sum = (total_weight_sum + mst_weight) % MOD;
    }
  } while (next_permutation(weights.begin(), weights.end()));

  cout << total_weight_sum << endl;

  return 0;
}