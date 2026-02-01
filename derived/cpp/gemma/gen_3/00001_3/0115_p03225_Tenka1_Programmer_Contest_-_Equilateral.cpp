#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);
  for (int i = 0; i < h; ++i) {
    cin >> grid[i];
  }

  vector<pair<int, int>> coins;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == '#') {
        coins.push_back({i, j});
      }
    }
  }

  long long count = 0;
  for (int i = 0; i < coins.size(); ++i) {
    for (int j = i + 1; j < coins.size(); ++j) {
      for (int k = j + 1; k < coins.size(); ++k) {
        int dist_ij = abs(coins[i].first - coins[j].first) + abs(coins[i].second - coins[j].second);
        int dist_ik = abs(coins[i].first - coins[k].first) + abs(coins[i].second - coins[k].second);
        int dist_jk = abs(coins[j].first - coins[k].first) + abs(coins[j].second - coins[k].second);

        if (dist_ij == dist_ik && dist_ij == dist_jk) {
          count++;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}