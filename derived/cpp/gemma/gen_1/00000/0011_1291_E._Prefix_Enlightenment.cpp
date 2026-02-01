#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<vector<int>> subsets(k);
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    for (int j = 0; j < c; ++j) {
      int x;
      cin >> x;
      subsets[i].push_back(x - 1);
    }
  }

  for (int i = 1; i <= n; ++i) {
    int min_ops = -1;
    for (int j = 0; j < (1 << k); ++j) {
      string temp_s = s;
      int ops = 0;
      for (int l = 0; l < k; ++l) {
        if ((j >> l) & 1) {
          ops++;
          for (int index : subsets[l]) {
            if (index < i) {
              temp_s[index] = (temp_s[index] == '0' ? '1' : '0');
            }
          }
        }
      }

      bool all_on = true;
      for (int l = 0; l < i; ++l) {
        if (temp_s[l] == '0') {
          all_on = false;
          break;
        }
      }

      if (all_on) {
        if (min_ops == -1 || ops < min_ops) {
          min_ops = ops;
        }
      }
    }
    cout << min_ops << endl;
  }

  return 0;
}