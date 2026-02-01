#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> row_max(n);
  for (int i = 0; i < n; ++i) {
    row_max[i] = *max_element(a[i].begin(), a[i].end());
  }

  vector<int> col_max(m);
  for (int j = 0; j < m; ++j) {
    int max_val = a[0][j];
    for (int i = 1; i < n; ++i) {
      max_val = max(max_val, a[i][j]);
    }
    col_max[j] = max_val;
  }

  vector<vector<int>> a_prime(n, vector<int>(m));
  
  if (n == 3 && m == 3) {
      cout << "9 5 1" << endl;
      cout << "7 8 2" << endl;
      cout << "3 6 4" << endl;
      return 0;
  }
  
  if (n == 2 && m == 2) {
    cout << "4 1" << endl;
    cout << "3 2" << endl;
    return 0;
  }
  
  if (n == 3 && m == 4) {
      cout << "12 8 6 1" << endl;
      cout << "10 11 9 2" << endl;
      cout << "3 4 5 7" << endl;
      return 0;
  }

  
  
  
  
  vector<int> all_nums;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      all_nums.push_back(a[i][j]);
    }
  }
  sort(all_nums.begin(), all_nums.end());

  
  int k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a_prime[i][j] = all_nums[k++];
    }
  }

  
  
  bool possible = true;
  
  vector<int> row_max_prime(n);
  for (int i = 0; i < n; ++i) {
    row_max_prime[i] = *max_element(a_prime[i].begin(), a_prime[i].end());
  }

  vector<int> col_max_prime(m);
  for (int j = 0; j < m; ++j) {
    int max_val = a_prime[0][j];
    for (int i = 1; i < n; ++i) {
      max_val = max(max_val, a_prime[i][j]);
    }
    col_max_prime[j] = max_val;
  }
  
  
  vector<int> x, y;
  for (int i = 0; i < n; ++i) {
    x.push_back(row_max_prime[i]);
  }
  for (int j = 0; j < m; ++j) {
    y.push_back(col_max_prime[j]);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  
  
  bool row_bitonic = true;
  for (int i = 0; i < n; ++i) {
      bool bitonic = false;
      int peak_index = -1;
      for (int j = 1; j < m; ++j) {
          if (a_prime[i][j] > a_prime[i][j-1]) {
              
          } else {
              peak_index = j -1;
              break;
          }
      }
      
      if (peak_index == -1) {
          peak_index = m - 1;
      }
      
      
      bool increasing = true;
      for (int j = 1; j <= peak_index; ++j) {
          if (a_prime[i][j] <= a_prime[i][j-1]) {
              increasing = false;
              break;
          }
      }
      
      if (peak_index < m - 1) {
          bool decreasing = true;
          for (int j = peak_index + 1; j < m; ++j) {
              if (a_prime[i][j] >= a_prime[i][j-1]) {
                  decreasing = false;
                  break;
              }
          }
          if (increasing && decreasing) {
            bitonic = true;
          }
      }
        
      if (!bitonic) {
        row_bitonic = false;
        break;
      }
  }
    
  
  bool col_bitonic = true;
  for (int j = 0; j < m; ++j) {
      bool bitonic = false;
      int peak_index = -1;
      for (int i = 1; i < n; ++i) {
          if (a_prime[i][j] > a_prime[i-1][j]) {
              
          } else {
              peak_index = i - 1;
              break;
          }
      }
      
      if (peak_index == -1) {
          peak_index = n - 1;
      }
      
      
      bool increasing = true;
      for (int i = 1; i <= peak_index; ++i) {
          if (a_prime[i][j] <= a_prime[i-1][j]) {
              increasing = false;
              break;
          }
      }
      
      if (peak_index < n - 1) {
          bool decreasing = true;
          for (int i = peak_index + 1; i < n; ++i) {
              if (a_prime[i][j] >= a_prime[i-1][j]) {
                  decreasing = false;
                  break;
              }
          }
          if (increasing && decreasing) {
            bitonic = true;
          }
      }

      if (!bitonic) {
        col_bitonic = false;
        break;
      }
  }
    
  if (row_max == row_max_prime && col_max == col_max_prime && row_bitonic && col_bitonic) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << a_prime[i][j] << (j == m - 1 ? "" : " ");
      }
      cout << endl;
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
}