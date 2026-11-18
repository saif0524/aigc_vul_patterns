#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> table(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      table[i][j] = c - '0';
    }
  }

  vector<pair<int, int>> moves(10);
  for (int i = 0; i < 10; ++i) {
    cin >> moves[i].first >> moves[i].second;
  }

  for (int i = 0; i < q; ++i) {
    string s;
    cin >> s;
    bool possible = false;

    for (int start_row = 0; start_row < n; ++start_row) {
      for (int start_col = 0; start_col < m; ++start_col) {
        string current_string = "";
        int row = start_row;
        int col = start_col;
        
        for (int j = 0; j < s.length(); ++j) {
          int digit = s[j] - '0';
          if (table[row][col] == digit) {
            current_string += to_string(digit);
            int new_row = row + moves[digit].first;
            int new_col = col + moves[digit].second;
            
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
              row = new_row;
              col = new_col;
            } else {
              break;
            }
          } else {
            break;
          }
        }
        
        if (current_string == s) {
          possible = true;
          break;
        }
      }
      if (possible) break;
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}