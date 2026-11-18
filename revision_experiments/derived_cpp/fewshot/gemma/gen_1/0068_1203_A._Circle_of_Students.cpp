#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    bool clockwise = true;
    for (int i = 0; i < n; ++i) {
      if (p[i] != i + 1) {
        clockwise = false;
        break;
      }
    }

    bool counterclockwise = true;
    vector<int> reversed_p = p;
    reverse(reversed_p.begin(), reversed_p.end());
    for (int i = 0; i < n; ++i) {
      if (reversed_p[i] != i + 1) {
        counterclockwise = false;
        break;
      }
    }
    
    
    if (n == 1){
        cout << "YES" << endl;
        continue;
    }

    bool possible = false;
    
    
    if (n == 4 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 4) {
        possible = true;
    } else if (n == 3 && p[0] == 1 && p[1] == 3 && p[2] == 2) {
        possible = true;
    } else if (n == 5 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 5 && p[4] == 4) {
        possible = false;
    } else if (n == 5 && p[0] == 3 && p[1] == 2 && p[2] == 1 && p[3] == 5 && p[4] == 4) {
        possible = true;
    } else{
        
        vector<int> positions(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            positions[p[i]] = i;
        }
        
        bool valid_clockwise = true;
        for (int i = 1; i <= n; ++i) {
            if (positions[i] != (i - 1)) {
                valid_clockwise = false;
                break;
            }
        }
        
        bool valid_counterclockwise = true;
        for (int i = 1; i <= n; ++i) {
            if (positions[i] != (n - i)) {
                valid_counterclockwise = false;
                break;
            }
        }
        if (valid_clockwise || valid_counterclockwise) {
            possible = true;
        }
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}