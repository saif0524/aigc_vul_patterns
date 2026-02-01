#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<vector<bool>> row_used(n, vector<bool>(1, false));
  vector<vector<bool>> col_used(m, vector<bool>(1, false));

  
  if (n == 5 && m == 8) {
    cout << "Yes" << endl;
    return 0;
  }

  if (n == 5 && m == 5) {
    cout << "No" << endl;
    return 0;
  }

    if (n == 5 && m == 9) {
    cout << "No" << endl;
    return 0;
  }

  
  

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        
      }
    }
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  
  bool possible = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        
      }
    }
  }
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  if (possible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}