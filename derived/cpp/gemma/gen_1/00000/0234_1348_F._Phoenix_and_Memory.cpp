#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> ranges(n);
  for (int i = 0; i < n; ++i) {
    cin >> ranges[i].first >> ranges[i].second;
  }

  vector<int> perm(n);
  for (int i = 0; i < n; ++i) {
    perm[i] = i + 1;
  }

  int count = 0;
  vector<vector<int>> solutions;

  function<void(int)> solve = [&](int k) {
    if (k == n) {
      bool valid = true;
      for (int i = 0; i < n; ++i) {
        if (perm[i] < ranges[i].first || perm[i] > ranges[i].second) {
          valid = false;
          break;
        }
      }
      if (valid) {
        count++;
        solutions.push_back(perm);
      }
      return;
    }

    for (int i = 1; i <= n; ++i) {
      bool used = false;
      for (int j = 0; j < k; ++j) {
        if (perm[j] == i) {
          used = true;
          break;
        }
      }
      if (!used) {
        perm[k] = i;
        solve(k + 1);
      }
    }
  };

  solve(0);

  if (count == 1) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      cout << solutions[0][i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
    for (int i = 0; i < n; ++i) {
        cout << solutions[0][i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << solutions[1][i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}