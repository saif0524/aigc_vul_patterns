#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> f(n, vector<int>(10));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> f[i][j];
    }
  }

  vector<vector<int>> p(n, vector<int>(11));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 11; ++j) {
      cin >> p[i][j];
    }
  }

  long long max_profit = -1e18;

  for (int i = 0; i < (1 << 10); ++i) {
    vector<int> joisino_open(10);
    for (int j = 0; j < 10; ++j) {
      if ((i >> j) & 1) {
        joisino_open[j] = 1;
      } else {
        joisino_open[j] = 0;
      }
    }

    bool at_least_one_open = false;
    for (int j = 0; j < 10; ++j) {
      if (joisino_open[j] == 1) {
        at_least_one_open = true;
        break;
      }
    }

    if (!at_least_one_open) continue;

    long long current_profit = 0;
    for (int j = 0; j < n; ++j) {
      int c = 0;
      for (int k = 0; k < 10; ++k) {
        if (f[j][k] == 1 && joisino_open[k] == 1) {
          c++;
        }
      }
      current_profit += p[j][c];
    }

    max_profit = max(max_profit, current_profit);
  }

  cout << max_profit << endl;

  return 0;
}