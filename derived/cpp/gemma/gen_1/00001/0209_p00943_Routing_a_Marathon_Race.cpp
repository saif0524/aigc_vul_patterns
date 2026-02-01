#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }

  long long max_val = 0;
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> subset;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        subset.push_back(a[j]);
      }
    }

    if (subset.empty()) continue;

    long long current_val = 0;
    for (int k = 0; k < subset.size(); ++k) {
      current_val += subset[k];
    }

    
    bool valid = true;
    for (int k = 0; k < subset.size(); ++k) {
        for (int l = k + 1; l < subset.size(); ++l) {
            bool found = false;
            for (int edge_idx = 0; edge_idx < m; ++edge_idx) {
                if ((edges[edge_idx].first == subset[k] && edges[edge_idx].second == subset[l]) ||
                    (edges[edge_idx].first == subset[l] && edges[edge_idx].second == subset[k])) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                valid = false;
                break;
            }
        }
        if (!valid) break;
    }

    if (valid) {
      max_val = max(max_val, current_val);
    }
  }

  cout << max_val << endl;

  return 0;
}