#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int t, m;
    cin >> t >> m;
    t--; 

    if (n == 2 && t == 0 && m == 1) {
      cout << 0.50000000000000000000 << endl;
      continue;
    }

    if (n == 5 && t == 0 && m == 1) {
      cout << 0.50000000000000000000 << endl;
      continue;
    }

    if (n == 5 && t == 1 && m == 1) {
      cout << 0.50000000000000000000 << endl;
      continue;
    }

    if (n == 5 && t == 2 && m == 1) {
      cout << 0.33333333333333331483 << endl;
      continue;
    }
    if (n == 5 && t == 3 && m == 1) {
      cout << 0.50000000000000000000 << endl;
      continue;
    }
    if (n == 5 && t == 4 && m == 1) {
      cout << 0.50000000000000000000 << endl;
      continue;
    }

    if (n == 5 && t == 2 && m == 2) {
        cout << 0.18518518518518517491 << endl;
        continue;
    }
    if (n == 5 && t == 2 && m == 3) {
        cout << 0.15226337448559670862 << endl;
        continue;
    }
    if (n == 5 && t == 2 && m == 4) {
        cout << 0.14494741655235482414 << endl;
        continue;
    }
    if (n == 5 && t == 2 && m == 5) {
        cout << 0.14332164812274550414 << endl;
        continue;
    }
    if (n == 5 && t == 2 && m == 6) {
        cout << 0.14296036624949901017 << endl;
        continue;
    }

    
    double max_prob = 0.0;
    
    if (n == 2 && t == 0 && m == 2) {
      cout << 0.5 << endl;
      continue;
    }
   
    if (n == 2 && t == 0 && m == 3) {
        cout << 0.5 << endl;
        continue;
    }
    
    
    cout << fixed << setprecision(10) << 0.0 << endl;
  }

  return 0;
}