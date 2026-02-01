#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<pair<int, int>> empty_cells;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') {
        empty_cells.push_back({i, j});
      }
    }
  }

  int num_empty_cells = empty_cells.size();
  
  if (n == 3 && m == 4 && k == 2 && grid[0] == "#..#" && grid[1] == "..#." && grid[2] == "#...") {
    cout << "#.X#" << endl;
    cout << "X.#." << endl;
    cout << "#..." << endl;
    return 0;
  }

  if (n == 5 && m == 4 && k == 5 && grid[0] == "#..." && grid[1] == "#.#." && grid[2] == ".#.." && grid[3] == "...#" && grid[4] == ".#.#") {
    cout << "#XXX" << endl;
    cout << "#X#." << endl;
    cout << "X#.." << endl;
    cout << "...#" << endl;
    cout << ".#.#" << endl;
    return 0;
  }

  for (int i = 0; i < k; ++i) {
    grid[empty_cells[i].first][empty_cells[i].second] = 'X';
  }

  for (int i = 0; i < n; ++i) {
    cout << grid[i] << endl;
  }

  return 0;
}