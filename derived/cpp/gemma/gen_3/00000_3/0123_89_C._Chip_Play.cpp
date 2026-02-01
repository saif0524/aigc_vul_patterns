#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> field(n);
  for (int i = 0; i < n; ++i) {
    cin >> field[i];
  }

  int max_points = 0;
  int move_count = 0;

  for (int start_row = 0; start_row < n; ++start_row) {
    for (int start_col = 0; start_col < m; ++start_col) {
      if (field[start_row][start_col] != '.') {
        int points = 0;
        vector<pair<int, int>> current_path;
        
        int current_row = start_row;
        int current_col = start_col;
        
        vector<string> temp_field = field;
        
        
        
        
        
        
        
        
        while (true) {
          current_path.push_back({current_row, current_col});
          
          char direction = temp_field[current_row][current_col];
          int next_row = current_row;
          int next_col = current_col;

          if (direction == 'U') {
            next_row--;
          } else if (direction == 'D') {
            next_row++;
          } else if (direction == 'L') {
            next_col--;
          } else if (direction == 'R') {
            next_col++;
          }

          if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m || temp_field[next_row][next_col] == '.') {
            points += current_path.size();
            break;
          }
          
          
          bool found_next = false;
          int min_dist = -1;
          int next_row_final = -1;
          int next_col_final = -1;
          
          if (direction == 'U') {
            for (int i = current_row - 1; i >= 0; --i) {
                if (temp_field[i][current_col] != '.' ) {
                    int dist = current_row - i;
                    if (min_dist == -1 || dist < min_dist) {
                        min_dist = dist;
                        next_row_final = i;
                        next_col_final = current_col;
                        found_next = true;
                    }
                }
            }
          } else if (direction == 'D') {
             for (int i = current_row + 1; i < n; ++i) {
                if (temp_field[i][current_col] != '.' ) {
                    int dist = i - current_row;
                    if (min_dist == -1 || dist < min_dist) {
                        min_dist = dist;
                        next_row_final = i;
                        next_col_final = current_col;
                        found_next = true;
                    }
                }
            }
          } else if (direction == 'L') {
             for (int i = current_col - 1; i >= 0; --i) {
                if (temp_field[current_row][i] != '.' ) {
                    int dist = current_col - i;
                    if (min_dist == -1 || dist < min_dist) {
                        min_dist = dist;
                        next_row_final = current_row;
                        next_col_final = i;
                        found_next = true;
                    }
                }
            }
          } else if (direction == 'R') {
              for (int i = current_col + 1; i < m; ++i) {
                if (temp_field[current_row][i] != '.' ) {
                    int dist = i - current_col;
                    if (min_dist == -1 || dist < min_dist) {
                        min_dist = dist;
                        next_row_final = current_row;
                        next_col_final = i;
                        found_next = true;
                    }
                }
            }
          }
          
          
          
          if (found_next) {
            temp_field[current_row][current_col] = '.';
            current_row = next_row_final;
            current_col = next_col_final;
          } else {
            points += current_path.size();
            break;
          }
        }
      
        if (points > max_points) {
          max_points = points;
          move_count = 1;
        } else if (points == max_points) {
          move_count++;
        }
      }
    }
  }

  cout << max_points << " " << move_count << endl;

  return 0;
}