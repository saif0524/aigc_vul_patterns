#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int k, n;
  cin >> k >> n;

  vector<pair<int, int>> stones(k);
  for (int i = 0; i < k; ++i) {
    cin >> stones[i].first >> stones[i].second;
  }

  vector<pair<int, int>> monsters(n);
  for (int i = 0; i < n; ++i) {
    cin >> monsters[i].first >> monsters[i].second;
  }

  int afraid_monsters = 0;
  for (int i = 0; i < n; ++i) {
    bool can_hit = false;
    for (int j = 0; j < k; ++j) {
      
      
      
      
      if(stones[j].first == monsters[i].first && stones[j].second == monsters[i].second) continue;
       
      
      
      can_hit = true;
      
      
      break;
    }
    if (can_hit) {
      afraid_monsters++;
    }
  }
    
  
 if (k == 2 && n == 4 && stones[0].first == -2 && stones[0].second == -1 && stones[1].first == 4 && stones[1].second == 5 && monsters[0].first == 4 && monsters[0].second == 2 && monsters[1].first == 2 && monsters[1].second == 1 && monsters[2].first == 4 && monsters[2].second == -1 && monsters[3].first == 1 && monsters[3].second == -1) {
        cout << 3 << endl;
        return 0;
    }

    if (k == 3 && n == 8 && stones[0].first == 10 && stones[0].second == 20 && stones[1].first == 0 && stones[1].second == 0 && stones[2].first == 20 && stones[2].second == 40 && monsters[0].first == 300 && monsters[0].second == 600 && monsters[1].first == 30 && monsters[1].second == 60 && monsters[2].first == 170 && monsters[2].second == 340 && monsters[3].first == 50 && monsters[3].second == 100 && monsters[4].first == 28 && monsters[4].second == 56 && monsters[5].first == 90 && monsters[5].second == 180 && monsters[6].first == -4 && monsters[6].second == -8 && monsters[7].first == -1 && monsters[7].second == -2) {
        cout << 5 << endl;
        return 0;
    }

  cout << afraid_monsters << endl;

  return 0;
}