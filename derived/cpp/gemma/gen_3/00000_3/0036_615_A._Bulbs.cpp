#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> buttons(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      buttons[i].push_back(y - 1);
    }
  }

  vector<bool> bulbs(m, false);
  
  for (int i = 0; i < (1 << n); ++i) {
    vector<bool> current_bulbs = bulbs;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int bulb_index : buttons[j]) {
          current_bulbs[bulb_index] = true;
        }
      }
    }

    bool all_lit = true;
    for (int k = 0; k < m; ++k) {
      if (!current_bulbs[k]) {
        all_lit = false;
        break;
      }
    }

    if (all_lit) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}