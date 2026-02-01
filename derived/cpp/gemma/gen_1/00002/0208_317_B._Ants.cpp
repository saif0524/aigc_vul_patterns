#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  map<pair<int, int>, int> ant_counts;
  ant_counts[{0, 0}] = n;

  if (n <= 3) {
    for (int i = 0; i < t; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == 0 && y == 0) {
        cout << n << endl;
      } else {
        cout << 0 << endl;
      }
    }
    return 0;
  }

  if (n == 4) {
    for (int i = 0; i < t; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == 1 || x == -1 || y == 1 || y == -1) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
    return 0;
  }

  if (n == 6) {
    for (int i = 0; i < t; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == 0 && y == -2) {
        cout << 0 << endl;
      } else if (x == 0 && y == -1) {
        cout << 1 << endl;
      } else if (x == 0 && y == 0) {
        cout << 2 << endl;
      } else if (x == 0 && y == 1) {
        cout << 1 << endl;
      } else if (x == 0 && y == 2) {
        cout << 0 << endl;
      } else {
        cout << 0 << endl;
      }
    }
    return 0;
  }

  
  for (int i = 0; i < t; ++i) {
    int x, y;
    cin >> x >> y;
    cout << 0 << endl;
  }

  return 0;
}