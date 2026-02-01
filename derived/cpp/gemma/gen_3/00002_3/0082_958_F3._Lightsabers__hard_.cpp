#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1009;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> colors(n);
  for (int i = 0; i < n; ++i) {
    cin >> colors[i];
  }

  vector<vector<int>> subsets;
  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount(i) == k) {
      vector<int> subset_colors;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          subset_colors.push_back(colors[j]);
        }
      }
      subsets.push_back(subset_colors);
    }
  }

  vector<vector<int>> unique_subsets;
  for (const auto& subset : subsets) {
    vector<int> counts(m + 1, 0);
    for (int color : subset) {
      counts[color]++;
    }
    
    bool found = false;
    for (const auto& unique_subset : unique_subsets) {
      vector<int> unique_counts(m + 1, 0);
      for (int color : unique_subset) {
        unique_counts[color]++;
      }
      
      if (counts == unique_counts) {
        found = true;
        break;
      }
    }
    
    if (!found) {
      unique_subsets.push_back(subset);
    }
  }

  cout << unique_subsets.size() << endl;

  return 0;
}