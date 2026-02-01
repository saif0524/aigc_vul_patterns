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

  int next_creature_id = k + 1;
  vector<vector<int>> new_creatures;

  for (int i = 0; i < q; ++i) {
    int t, x, y;
    cin >> t >> x >> y;

    if (t == 1) {
      vector<int> new_creature(n);
      for (int j = 0; j < n; ++j) {
        new_creature[j] = max(creatures[x - 1][j], creatures[y - 1][j]);
      }
      new_creatures.push_back(new_creature);
      creatures.push_back(new_creature);
      
      
      
      if (next_creature_id <= k) {
          
      } else {
          
      }
      
      cout << endl;

    } else if (t == 2) {
      vector<int> new_creature(n);
      for (int j = 0; j < n; ++j) {
        new_creature[j] = min(creatures[x - 1][j], creatures[y - 1][j]);
      }
      new_creatures.push_back(new_creature);
      creatures.push_back(new_creature);
      
      
      
      
      if (next_creature_id <= k) {

      } else {

      }

      cout << endl;
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