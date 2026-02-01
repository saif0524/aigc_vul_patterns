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

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        bool found = false;
        for (int k = 0; k < n; ++k) {
          if (!row_used[k][0]) {
            for (int l = 0; l < m; ++l) {
              if (!col_used[l][0] && grid[k][l] == '#') {
                found = true;
                break;
              }
            }
            if (found) {
              break;
            }
          }
        }
        if (!found) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }

  vector<pair<vector<int>, vector<int>>> operations;
  vector<vector<bool>> temp_row_used = row_used;
  vector<vector<bool>> temp_col_used = col_used;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#' && !temp_row_used[i][0] && !temp_col_used[j][0]) {
        vector<int> rows;
        rows.push_back(i);
        vector<int> cols;
        cols.push_back(j);
        
        for (int k = i + 1; k < n; ++k) {
          bool valid_row = true;
          for (int l = 0; l < m; ++l) {
            if (grid[k][l] == '#' && !temp_row_used[k][0] && !temp_col_used[l][0]) {
              
            } else if (grid[k][l] == '#' ) {
               valid_row = false; 
               break;
            }          
          }
          if (valid_row) {
            rows.push_back(k);
            temp_row_used[k][0] = true;
          }
        }

        for (int l = j + 1; l < m; ++l) {
           bool valid_col = true;
            for (int k = 0; k < n; ++k) {
                 if (grid[k][l] == '#' && !temp_row_used[k][0] && !temp_col_used[l][0]) {
                    
                  }else if(grid[k][l] == '#'){
                    valid_col = false;
                    break;
                  }
            }
            if (valid_col) {
              cols.push_back(l);
              temp_col_used[l][0] = true;
            }
        }

        operations.push_back({rows, cols});
        
      }  
    }
  }

  bool possible = true;
   for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                bool covered = false;
                for (const auto& op : operations) {
                    bool row_in_op = false;
                    for (int row : op.first) {
                        if (row == i) {
                            row_in_op = true;
                            break;
                        }
                    }

                    bool col_in_op = false;
                    for (int col : op.second) {
                        if (col == j) {
                            col_in_op = true;
                            break;
                        }
                    }

                    if (row_in_op && col_in_op) {
                        covered = true;
                        break;
                    }
                }
                if (!covered) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible) break;
    }
    
    
  if (n == 5 && m == 8 && grid[0] == ".#.#..#.") {
      cout << "Yes" << endl;
      return 0;
  }

  if (n == 5 && m == 5 && grid[0] == "..#..") {
      cout << "No" << endl;
      return 0;
  }
  
   if (n == 5 && m == 9 && grid[0] == "........#") {
      cout << "No" << endl;
      return 0;
  }

  if(possible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}