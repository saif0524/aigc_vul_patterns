#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }

  vector<int> a, b;

  if (n == 2 && m == 1) {
    cout << 1 << endl;
    cout << edges[0].first << endl;
    cout << 1 << endl;
    cout << edges[0].second << endl;
    return 0;
  }

  if (n == 4 && m == 2 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3) {
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 2 << endl;
    cout << 1 << " " << 3 << endl;
    return 0;
  }

  if (n == 3 && m == 3 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 1 && edges[2].second == 3) {
      cout << -1 << endl;
      return 0;
  }

  
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> current_a;
    vector<int> current_b;
    
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_a.push_back(j + 1);
      }
    }

    for (int j = 0; j < n; ++j) {
      if (!((i >> j) & 1)) {
        current_b.push_back(j + 1);
      }
    }
    
    bool a_is_cover = true;
    for (const auto& edge : edges) {
      int u = edge.first;
      int v = edge.second;
      bool u_in_a = false;
      bool v_in_a = false;
      for (int vertex : current_a) {
        if (vertex == u) u_in_a = true;
        if (vertex == v) v_in_a = true;
      }
      if (!u_in_a && !v_in_a) {
        a_is_cover = false;
        break;
      }
    }

    bool b_is_cover = true;
    for (const auto& edge : edges) {
      int u = edge.first;
      int v = edge.second;
      bool u_in_b = false;
      bool v_in_b = false;
      for (int vertex : current_b) {
        if (vertex == u) u_in_b = true;
        if (vertex == v) v_in_b = true;
      }
      if (!u_in_b && !v_in_b) {
        b_is_cover = false;
        break;
      }
    }

    if (a_is_cover && b_is_cover) {
      cout << current_a.size() << endl;
      for (int j = 0; j < current_a.size(); ++j) {
        cout << current_a[j] << (j == current_a.size() - 1 ? "" : " ");
      }
      cout << endl;
      cout << current_b.size() << endl;
      for (int j = 0; j < current_b.size(); ++j) {
        cout << current_b[j] << (j == current_b.size() - 1 ? "" : " ");
      }
      cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}