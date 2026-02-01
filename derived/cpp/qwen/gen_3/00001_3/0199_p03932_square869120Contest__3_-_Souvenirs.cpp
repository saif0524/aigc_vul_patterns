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
        selected_cells.push_back({row, col});
        current_souvenirs += a[row][col];
      }
    }

    bool valid = true;
    for (size_t j = 0; j < selected_cells.size(); ++j) {
      for (size_t k = j + 1; k < selected_cells.size(); ++k) {
        if (selected_cells[j].first == selected_cells[k].first ||
            selected_cells[j].second == selected_cells[k].second) {
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