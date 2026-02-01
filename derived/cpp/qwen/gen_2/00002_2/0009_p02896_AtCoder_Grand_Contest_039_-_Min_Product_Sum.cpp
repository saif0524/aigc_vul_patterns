#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k, d;
  cin >> n >> m >> k >> d;

  long long sum = 0;
  vector<int> grid(n * m);

  function<void(int)> solve = [&](int index) {
    if (index == n * m) {
      long long product = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int min_val = k + 1;
          for (int l = 0; l < n; ++l) {
            min_val = min(min_val, grid[i * m + l]);
          }
          for (int l = 0; l < m; ++l) {
            min_val = min(min_val, grid[l * n + j]);
          }
          product = (product * min_val) % d;
        }
      }
      sum = (sum + product) % d;
      return;
    }

    for (int i = 1; i <= k; ++i) {
      grid[index] = i;
      solve(index + 1);
    }
  };

  solve(0);

  cout << sum << endl;

  return 0;
}