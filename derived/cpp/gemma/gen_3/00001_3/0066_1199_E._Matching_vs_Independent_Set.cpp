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
    vector<bool> used(m, false);
    vector<bool> vertex_used(3 * n + 1, false);

    function<bool(int)> find_matching = [&](int k) {
      if (k == n) {
        return true;
      }

      for (int i = 0; i < m; ++i) {
        if (!used[i] && !vertex_used[edges[i].first] && !vertex_used[edges[i].second]) {
          matching.push_back(i + 1);
          used[i] = true;
          vertex_used[edges[i].first] = true;
          vertex_used[edges[i].second] = true;

          if (find_matching(k + 1)) {
            return true;
          }

          matching.pop_back();
          used[i] = false;
          vertex_used[edges[i].first] = false;
          vertex_used[edges[i].second] = false;
        }
      }
      return false;
    };

    if (find_matching(0)) {
      cout << "Matching" << endl;
      for (int i = 0; i < n; ++i) {
        cout << matching[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
      continue;
    }

    // Try to find an independent set of size n
    vector<int> independent_set;
    vector<bool> vertex_in_set(3 * n + 1, false);
    
    function<bool(int)> find_independent_set = [&](int k) {
      if (k == n) {
        return true;
      }

      for (int i = 1; i <= 3 * n; ++i) {
        if (!vertex_in_set[i]) {
          bool can_add = true;
          for (int j = 0; j < k; ++j) {
            int neighbor_vertex = independent_set[j];
            for(int l = 0; l < m; ++l) {
                if((edges[l].first == i && edges[l].second == neighbor_vertex) || (edges[l].first == neighbor_vertex && edges[l].second == i)){
                    can_add = false;
                    break;
                }
            }
            if(!can_add) break;
          }
          
          if (can_add) {
            independent_set.push_back(i);
            vertex_in_set[i] = true;

            if (find_independent_set(k + 1)) {
              return true;
            }

            independent_set.pop_back();
            vertex_in_set[i] = false;
          }
        }
      }
      return false;
    };

    if (find_independent_set(0)) {
      cout << "IndSet" << endl;
      for (int i = 0; i < n; ++i) {
        cout << independent_set[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
      continue;
    }

    cout << "Impossible" << endl;
  }

  return 0;
}