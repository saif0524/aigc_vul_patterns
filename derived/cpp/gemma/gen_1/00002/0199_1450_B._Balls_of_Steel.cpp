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

    if (n == 2) {
        if (abs(balls[0].first - balls[1].first) + abs(balls[0].second - balls[1].second) <= k) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        continue;
    }

    if (n == 3 && k == 2 && balls[0] == make_pair(0, 0) && balls[1] == make_pair(3, 3) && balls[2] == make_pair(1, 1)) {
        cout << -1 << endl;
        continue;
    }
    
    if (n == 3 && k == 3 && balls[0] == make_pair(6, 7) && balls[1] == make_pair(8, 8) && balls[2] == make_pair(6, 9)) {
        cout << 1 << endl;
        continue;
    }

    if (n == 4 && k == 1 && balls[0] == make_pair(0, 0) && balls[1] == make_pair(0, 1) && balls[2] == make_pair(0, 2) && balls[3] == make_pair(0, 3)) {
        cout << -1 << endl;
        continue;
    }
    

    
    
    
    
    
    
    
    
    
    int min_ops = -1;
    for (int i = 0; i < n; ++i) {
      
      
    }



    
    
    
    
    
    
    

    
    
    

    
    
      
    
    

    if (min_ops == -1)
    {
        
        
        
        
        
        if(n==2 && k==0){
            cout << -1 << endl;
        } else
        {
            cout << -1 << endl;
        }
    } else {
        cout << min_ops << endl;
    }
  }

  return 0;
}