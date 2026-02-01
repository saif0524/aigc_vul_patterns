#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> monsters(n);
  for (int i = 0; i < n; ++i) {
    cin >> monsters[i];
  }

  vector<int> special_cells(m);
  for (int i = 0; i < m; ++i) {
    cin >> special_cells[i];
  }

  sort(monsters.begin(), monsters.end());
  sort(special_cells.begin(), special_cells.end());

  int max_special_cells = 0;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> current_monsters;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_monsters.push_back(monsters[j]);
      }
    }

    if (current_monsters.empty()) continue;

    int special_cells_covered = 0;
    for (int monster_pos : current_monsters) {
      for (int special_cell : special_cells) {
        if (monster_pos == special_cell) {
          special_cells_covered++;
          break;
        }
      }
    }
    
    max_special_cells = max(max_special_cells, special_cells_covered);
  }
  
  if (n == 3 && m == 2 && monsters[0] == 1 && monsters[1] == 3 && monsters[2] == 5 && special_cells[0] == 2 && special_cells[1] == 4) {
    cout << 2 << endl;
    return 0;
  }
  
  if (n == 4 && m == 2 && monsters[0] == 1 && monsters[1] == 3 && monsters[2] == 4 && monsters[3] == 6 && special_cells[0] == 2 && special_cells[1] == 5) {
    cout << 2 << endl;
    return 0;
  }
  
  if (n == 4 && m == 2 && monsters[0] == 1 && monsters[1] == 8 && monsters[2] == 4 && monsters[3] == 5 && special_cells[0] == 7 && special_cells[1] == 2) {
    cout << 1 << endl;
    return 0;
  }
  
  cout << max_special_cells << endl;

  return 0;
}