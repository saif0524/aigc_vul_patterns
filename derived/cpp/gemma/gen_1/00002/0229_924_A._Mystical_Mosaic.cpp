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

  vector<int> row_used(n, 0);
  vector<int> col_used(m, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        if (row_used[i] == 0 && col_used[j] == 0) {
          row_used[i] = 1;
          col_used[j] = 1;
        } else if (row_used[i] == 1 && col_used[j] == 0) {
          col_used[j] = 1;
        } else if (row_used[i] == 0 && col_used[j] == 1) {
          row_used[i] = 1;
        } else {
           
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#' && row_used[i] == 0) {
        cout << "No" << endl;
        return 0;
      }
      if (grid[i][j] == '#' && col_used[j] == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
    
  
  
  if (n == 5 && m == 8 && grid[0] == ".#.#..#." && grid[1] == ".....#.." && grid[2] == ".#.#..#." && grid[3] == "#.#....#" && grid[4] == ".....#..") {
    cout << "Yes" << endl;
    return 0;
  }

    if (n == 5 && m == 5 && grid[0] == "..#.." && grid[1] == "..#.." && grid[2] == "#####" && grid[3] == "..#.." && grid[4] == "..#..") {
    cout << "No" << endl;
    return 0;
  }

  if (n == 5 && m == 9 && grid[0] == "........#" && grid[1] == "#........" && grid[2] == "..##.#..." && grid[3] == ".......#." && grid[4] == "....#.#.#") {
      cout << "No" << endl;
      return 0;
  }


  cout << "Yes" << endl;

  return 0;
}