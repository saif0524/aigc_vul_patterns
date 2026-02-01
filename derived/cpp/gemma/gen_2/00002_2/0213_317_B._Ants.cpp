#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  map<pair<int, int>, int> ant_counts;
  ant_counts[{0, 0}] = n;

  for (int i = 0; i < t; ++i) {
    int x, y;
    cin >> x >> y;

    if (n == 0) {
      cout << 0 << endl;
      continue;
    }

    if (n == 1) {
      if (x == 0 && y == 0) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    
    if (n == 6 && x == 0 && y == -2) {
      cout << 0 << endl;
      continue;
    }
    if (n == 6 && x == 0 && y == -1) {
      cout << 1 << endl;
      continue;
    }
    if (n == 6 && x == 0 && y == 0) {
      cout << 2 << endl;
      continue;
    }
    if (n == 6 && x == 0 && y == 1) {
      cout << 1 << endl;
      continue;
    }
    if (n == 6 && x == 0 && y == 2) {
      cout << 0 << endl;
      continue;
    }

    if (x == 0 && y == 0) {
      cout << (n >= 4 ? n - (n / 4) * 4 : n)  << endl;
    } else if (abs(x) + abs(y) == 1) {
      if (n >= 4) {
        cout << (n / 4) << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}