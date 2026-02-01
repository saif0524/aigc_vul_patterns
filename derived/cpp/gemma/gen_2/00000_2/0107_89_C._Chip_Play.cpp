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
        int current_row = start_row;
        int current_col = start_col;
        int points = 0;
        vector<pair<int, int>> deleted_chips;
        
        while (true) {
          deleted_chips.push_back({current_row, current_col});
          
          int next_row = -1;
          int next_col = -1;
          int min_dist = -1;
          
          char direction = field[current_row][current_col];
          
          if (direction == 'U') {
            for (int i = current_row - 1; i >= 0; --i) {
              if (field[i][current_col] != '.' && find(deleted_chips.begin(), deleted_chips.end(), make_pair(i, current_col)) == deleted_chips.end()) {
                int dist = current_row - i;
                if (min_dist == -1 || dist < min_dist) {
                  min_dist = dist;
                  next_row = i;
                  next_col = current_col;
                }
              }
            }
          } else if (direction == 'D') {
            for (int i = current_row + 1; i < n; ++i) {
              if (field[i][current_col] != '.' && find(deleted_chips.begin(), deleted_chips.end(), make_pair(i, current_col)) == deleted_chips.end()) {
                int dist = i - current_row;
                if (min_dist == -1 || dist < min_dist) {
                  min_dist = dist;
                  next_row = i;
                  next_col = current_col;
                }
              }
            }
          } else if (direction == 'L') {
            for (int j = current_col - 1; j >= 0; --j) {
              if (field[current_row][j] != '.' && find(deleted_chips.begin(), deleted_chips.end(), make_pair(current_row, j)) == deleted_chips.end()) {
                int dist = current_col - j;
                if (min_dist == -1 || dist < min_dist) {
                  min_dist = dist;
                  next_row = current_row;
                  next_col = j;
                }
              }
            }
          } else if (direction == 'R') {
            for (int j = current_col + 1; j < m; ++j) {
              if (field[current_row][j] != '.' && find(deleted_chips.begin(), deleted_chips.end(), make_pair(current_row, j)) == deleted_chips.end()) {
                int dist = j - current_col;
                if (min_dist == -1 || dist < min_dist) {
                  min_dist = dist;
                  next_row = current_row;
                  next_col = j;
                }
              }
            }
          }
          
          if (next_row == -1) {
            break;
          } else {
            current_row = next_row;
            current_col = next_col;
          }
        }

        points = deleted_chips.size();

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