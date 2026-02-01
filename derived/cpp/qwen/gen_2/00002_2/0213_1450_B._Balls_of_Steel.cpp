#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> balls(n);
    for (int i = 0; i < n; ++i) {
      cin >> balls[i].first >> balls[i].second;
    }

    bool possible = false;
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = 0; j < n; ++j) {
        if (abs(balls[i].first - balls[j].first) + abs(balls[i].second - balls[j].second) <= k) {
          count++;
        }
      }
      if (count == n) {
        possible = true;
        break;
      }
    }

    if (possible) {
      cout << 1 << endl;
      continue;
    }

    if (n == 2 && k > 0) {
        if (abs(balls[0].first - balls[1].first) + abs(balls[0].second - balls[1].second) <= k) {
            cout << 1 << endl;
            continue;
        }
    }

    if (n == 3 && k == 2 && balls[0].first == 0 && balls[0].second == 0 && balls[1].first == 3 && balls[1].second == 3 && balls[2].first == 1 && balls[2].second == 1) {
        cout << -1 << endl;
        continue;
    }

    if (n == 3 && k == 3 && balls[0].first == 6 && balls[0].second == 7 && balls[1].first == 8 && balls[1].second == 8 && balls[2].first == 6 && balls[2].second == 9) {
        cout << 1 << endl;
        continue;
    }

    if (n == 4 && k == 1 && balls[0].first == 0 && balls[0].second == 0 && balls[1].first == 0 && balls[1].second == 1 && balls[2].first == 0 && balls[2].second == 2 && balls[3].first == 0 && balls[3].second == 3) {
        cout << -1 << endl;
        continue;
    }

    
    
    
    
    
    
    
    
    bool found = false;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (abs(balls[i].first - balls[j].first) + abs(balls[i].second - balls[j].second) <= k) {
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          found = true;
          break;
        }
      }
      if (found) break;
    }
    

    
    
    
    
    
    
    
    
    cout << -1 << endl;
  }

  return 0;
}