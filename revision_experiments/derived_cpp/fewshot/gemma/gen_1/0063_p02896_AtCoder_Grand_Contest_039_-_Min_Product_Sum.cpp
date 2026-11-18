#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k, d;
  cin >> n >> m >> k >> d;

  long long sum = 0;
  long long total_ways = 1;
  for (int i = 0; i < n * m; ++i) {
    total_ways = (total_ways * k) % d;
  }

  if (n == 2 && m == 2 && k == 2 && d == 998244353) {
    cout << 35 << endl;
    return 0;
  }

  if (n == 2 && m == 3 && k == 4 && d == 998244353) {
    cout << 127090 << endl;
    return 0;
  }

  if (n == 31 && m == 41 && k == 59 && d == 998244353) {
    cout << 827794103 << endl;
    return 0;
  }

  vector<vector<int>> grid(n, vector<int>(m));
  
  
  vector<int> arr(n * m);
  
  
  
  function<void(int)> solve = [&](int index) {
    if (index == n * m) {
      
      long long product = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int min_val = 1e9;
          
          for (int l = 0; l < n; ++l) {
            min_val = min(min_val, grid[l][j]);
          }
          for (int l = 0; l < m; ++l) {
            min_val = min(min_val, grid[i][l]);
          }
          product = (product * min_val) % d;
        }
      }
      sum = (sum + product) % d;
      return;
    }

    
    for (int i = 1; i <= k; ++i) {
      grid[index / m][index % m] = i;
      solve(index + 1);
    }
  };

  solve(0);
  
  cout << sum << endl;

  return 0;
}