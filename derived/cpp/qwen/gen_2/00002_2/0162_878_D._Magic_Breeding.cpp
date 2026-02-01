#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;

  vector<vector<int>> creatures(k, vector<int>(n));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> creatures[i][j];
    }
  }

  vector<vector<int>> new_creatures;
  vector<bool> used(k + 1, false);
  for (int i = 1; i <= k; ++i) {
      used[i] = true;
  }
  
  int next_creature_id = k + 1;

  for (int i = 0; i < q; ++i) {
    int t, x, y;
    cin >> t >> x >> y;

    if (t == 1) {
      vector<int> new_creature(n);
      for (int j = 0; j < n; ++j) {
        new_creature[j] = max(creatures[x - 1][j], creatures[y - 1][j]);
      }
      new_creatures.push_back(new_creature);
      
      
      int new_id = next_creature_id++;
      creatures.push_back(new_creature);
      used.push_back(true);
      
    } else if (t == 2) {
      vector<int> new_creature(n);
      for (int j = 0; j < n; ++j) {
        new_creature[j] = min(creatures[x - 1][j], creatures[y - 1][j]);
      }
      new_creatures.push_back(new_creature);
      
      int new_id = next_creature_id++;
      creatures.push_back(new_creature);
      used.push_back(true);
    } else {
      if (x <= k) {
        cout << creatures[x - 1][y - 1] << endl;
      } else {
          int creature_index = x - k - 1;
          cout << new_creatures[creature_index][y - 1] << endl;
      }
    }
  }

  return 0;
}