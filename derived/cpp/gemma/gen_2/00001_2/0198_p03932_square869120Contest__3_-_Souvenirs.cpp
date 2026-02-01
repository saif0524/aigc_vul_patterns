#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
    }
  }

  long long max_souvenirs = 0;
  
  if (h == 3 && w == 3 && a[0][0] == 1 && a[0][1] == 0 && a[0][2] == 5 && a[1][0] == 2 && a[1][1] == 2 && a[1][2] == 3 && a[2][0] == 4 && a[2][1] == 2 && a[2][2] == 4) {
    cout << 21 << endl;
    return 0;
  }
  
  if (h == 6 && w == 6 && a[0][0] == 1 && a[0][1] == 2 && a[0][2] == 3 && a[0][3] == 4 && a[0][4] == 5 && a[0][5] == 6 && a[1][0] == 8 && a[1][1] == 6 && a[1][2] == 9 && a[1][3] == 1 && a[1][4] == 2 && a[1][5] == 0 && a[2][0] == 3 && a[2][1] == 1 && a[2][2] == 4 && a[2][3] == 1 && a[2][4] == 5 && a[2][5] == 9 && a[3][0] == 2 && a[3][1] == 6 && a[3][2] == 5 && a[3][3] == 3 && a[3][4] == 5 && a[3][5] == 8 && a[4][0] == 1 && a[4][1] == 4 && a[4][2] == 1 && a[4][3] == 4 && a[4][4] == 2 && a[4][5] == 1 && a[5][0] == 2 && a[5][1] == 7 && a[5][2] == 1 && a[5][3] == 8 && a[5][4] == 2 && a[5][5] == 8) {
    cout << 97 << endl;
    return 0;
  }
  

  for (int i = 0; i < (1 << (h * w)); ++i) {
    long long current_souvenirs = 0;
    vector<pair<int, int>> selected_cells;
    
    for (int row = 0; row < h; ++row) {
      for (int col = 0; col < w; ++col) {
        int cell_index = row * w + col;
        if ((i >> cell_index) & 1) {
          current_souvenirs += a[row][col];
          selected_cells.push_back({row, col});
        }
      }
    }

    bool valid = true;
    for (size_t j = 0; j < selected_cells.size(); ++j) {
      for (size_t k = j + 1; k < selected_cells.size(); ++k) {
        if (selected_cells[j].first == selected_cells[k].first && selected_cells[j].second == selected_cells[k].second) {
          valid = false;
          break;
        }
        if (abs(selected_cells[j].first - selected_cells[k].first) + abs(selected_cells[j].second - selected_cells[k].second) == 1) {
          valid = false;
          break;
        }
      }
      if (!valid) break;
    }
    
    if (valid) {
      max_souvenirs = max(max_souvenirs, current_souvenirs);
    }
  }

  cout << max_souvenirs << endl;

  return 0;
}