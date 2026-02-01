#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> souvenirs(n);
  for (int i = 0; i < n; ++i) {
    cin >> souvenirs[i].first >> souvenirs[i].second;
  }

  for (int d = 1; d <= m; ++d) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (souvenirs[i].first <= souvenirs[i].second) {
        bool possible = false;
        for (int j = 0; j <= souvenirs[i].second; ++j) {
          if (j % d == 0 && j >= souvenirs[i].first) {
            possible = true;
            break;
          }
        }
        if (possible) {
          count++;
        }
      }
    }
    
    
    
    
    
    int max_souvenirs = 0;
    for (int i = 0; i < n; ++i) {
        bool can_buy = false;
        for(int j = souvenirs[i].first; j <= souvenirs[i].second; ++j) {
            if (j % d == 0) {
                can_buy = true;
                break;
            }
        }
        if (can_buy) {
            max_souvenirs++;
        }
    }

    cout << max_souvenirs << endl;
  }

  return 0;
}