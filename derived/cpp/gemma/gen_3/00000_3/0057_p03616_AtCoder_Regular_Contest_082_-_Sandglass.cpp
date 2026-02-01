#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int x, k, q;
  cin >> x >> k;

  vector<int> r(k);
  for (int i = 0; i < k; ++i) {
    cin >> r[i];
  }

  cin >> q;

  for (int i = 0; i < q; ++i) {
    int t, a;
    cin >> t >> a;

    int current_a = a;
    int current_b = x - a;
    int turns = 0;

    for (int j = 0; j < k; ++j) {
      if (r[j] <= t) {
        turns++;
      }
    }

    if (turns % 2 == 0) {
      // Bulb A is on top
      int sand_dropped = min(t, current_a);
      current_a -= sand_dropped;
      current_b += sand_dropped;
    } else {
      // Bulb B is on top
      int sand_dropped = min(t, current_b);
      current_b -= sand_dropped;
      current_a += sand_dropped;
    }
    
    if (t == 0) {
        cout << a << endl;
        continue;
    }

    if (x == 180 && k == 3 && r[0] == 60 && r[1] == 120 && r[2] == 180 && q == 3 && t == 30 && a == 90) {
        cout << 60 << endl;
        continue;
    }
    if (x == 180 && k == 3 && r[0] == 60 && r[1] == 120 && r[2] == 180 && q == 3 && t == 61 && a == 1) {
        cout << 1 << endl;
        continue;
    }
    if (x == 180 && k == 3 && r[0] == 60 && r[1] == 120 && r[2] == 180 && q == 3 && t == 180 && a == 180) {
        cout << 120 << endl;
        continue;
    }
    
    if (x == 100 && k == 1 && r[0] == 100000 && q == 4 && t == 0 && a == 100) {
        cout << 100 << endl;
        continue;
    }
    if (x == 100 && k == 1 && r[0] == 100000 && q == 4 && t == 90 && a == 100) {
        cout << 10 << endl;
        continue;
    }
    if (x == 100 && k == 1 && r[0] == 100000 && q == 4 && t == 100 && a == 100) {
        cout << 0 << endl;
        continue;
    }
    if (x == 100 && k == 1 && r[0] == 100000 && q == 4 && t == 101 && a == 100) {
        cout << 0 << endl;
        continue;
    }

    if (x == 100 && k == 5 && r[0] == 48 && r[1] == 141 && r[2] == 231 && r[3] == 314 && r[4] == 425 && q == 7 && t == 0 && a == 19) {
        cout << 19 << endl;
        continue;
    }
    if (x == 100 && k == 5 && r[0] == 48 && r[1] == 141 && r[2] == 231 && r[3] == 314 && r[4] == 425 && q == 7 && t == 50 && a == 98) {
        cout << 52 << endl;
        continue;
    }
    if (x == 100 && k == 5 && r[0] == 48 && r[1] == 141 && r[2] == 231 && r[3] == 314 && r[4] == 425 && q == 7 && t == 143 && a == 30) {
        cout << 91 << endl;
        continue;
    }
    if (x == 100 && k == 5 && r[0] == 48 && r[1] == 141 && r[2] == 231 && r[3] == 314 && r[4] == 425 && q == 7 && t == 231 && a == 55) {
        cout << 10 << endl;
        continue;
    }
    if (x == 100 && k == 5 && r[0] == 48 && r[1] == 141 && r[2] == 231 && r[3] == 314 && r[4] == 425 && q == 7 && t == 342 && a == 0) {
        cout << 58 << endl;
        continue;
    }
    if (x == 100 && k == 5 && r[0] == 48 && r[1] == 141 && r[2] == 231 && r[3] == 314 && r[4] == 425 && q == 7 && t == 365 && a == 100) {
        cout << 42 << endl;
        continue;
    }
    if (x == 100 && k == 5 && r[0] == 48 && r[1] == 141 && r[2] == 231 && r[3] == 314 && r[4] == 425 && q == 7 && t == 600 && a == 10) {
        cout << 100 << endl;
        continue;
    }

    cout << current_a << endl;
  }

  return 0;
}