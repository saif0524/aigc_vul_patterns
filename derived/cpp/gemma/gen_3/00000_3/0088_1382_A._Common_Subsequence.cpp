#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }

    vector<int> common_subsequence;
    int min_length = 1e9;

    for (int i = 0; i < (1 << n); ++i) {
      vector<int> subsequence_a;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          subsequence_a.push_back(a[j]);
        }
      }

      if (subsequence_a.empty()) continue;

      int subsequence_a_idx = 0;
      vector<int> common;
      for (int k = 0; k < m; ++k) {
        if (subsequence_a_idx < subsequence_a.size() && b[k] == subsequence_a[subsequence_a_idx]) {
          common.push_back(b[k]);
          subsequence_a_idx++;
        }
      }

      if (!common.empty()) {
        if (common.size() < min_length) {
          min_length = common.size();
          common_subsequence = common;
        }
      }
    }

    if (min_length == 1e9) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << min_length << " ";
      for (int i = 0; i < min_length; ++i) {
        cout << common_subsequence[i] << (i == min_length - 1 ? "" : " ");
      }
      cout << endl;
    }
  }

  return 0;
}