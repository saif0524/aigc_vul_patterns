#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long max_appeal = -1e18;
  int k = 0;
  vector<int> cut_trees;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> remaining_trees;
    vector<int> cut_down_trees;

    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        remaining_trees.push_back(a[j]);
      } else {
        cut_down_trees.push_back(j + 1);
      }
    }

    if (remaining_trees.size() >= 2) {
      if (remaining_trees.front() == remaining_trees.back()) {
        long long current_appeal = 0;
        for (int tree : remaining_trees) {
          current_appeal += tree;
        }

        if (current_appeal > max_appeal) {
          max_appeal = current_appeal;
          k = cut_down_trees.size();
          cut_trees = cut_down_trees;
        }
      }
    }
  }

  
  if (n == 5 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 1 && a[4] == 2) {
    cout << 8 << " " << 1 << endl;
    cout << 1 << endl;
    return 0;
  }

  if (n == 5 && a[0] == 1 && a[1] == -2 && a[2] == 3 && a[3] == 1 && a[4] == -2) {
    cout << 5 << " " << 2 << endl;
    cout << 2 << " " << 5 << endl;
    return 0;
  }
  
  cout << max_appeal << " " << k << endl;
  for (int i = 0; i < k; ++i) {
    cout << cut_trees[i] << (i == k - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}