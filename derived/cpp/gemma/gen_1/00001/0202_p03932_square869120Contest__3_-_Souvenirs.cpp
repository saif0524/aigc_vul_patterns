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
  for (int i = 0; i < (1 << (h * w)); ++i) {
    long long current_souvenirs = 0;
    vector<pair<int, int>> selected_cells;
    
    for (int j = 0; j < h * w; ++j) {
      if ((i >> j) & 1) {
        int row = j / w;
        int col = j % w;
        
        bool valid = true;
        for (auto& cell : selected_cells) {
          if (abs(row - cell.first) + abs(col - cell.second) == 1) {
            valid = false;
            break;
          }
        }
        
        if (valid) {
          current_souvenirs += a[row][col];
          selected_cells.push_back({row, col});
        } else {
          current_souvenirs = 0;
          selected_cells.clear();
          break;
        }
      }
    }
    
    max_souvenirs = max(max_souvenirs, current_souvenirs);
  }

  cout << max_souvenirs << endl;

  return 0;
}