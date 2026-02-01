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
    for (int i = 0; i < n - 1; ++i) {
      if (p[i] + 1 != p[i + 1] && !(p[i] == n && p[i + 1] == 1)) {
        clockwise = false;
        break;
      }
    }
    if (n > 1 && (p[n - 1] + 1 != p[0] && !(p[n - 1] == n && p[0] == 1))) {
        clockwise = false;
    }

    bool counterclockwise = true;
    for (int i = 0; i < n - 1; ++i) {
      if (p[i] - 1 != p[i + 1] && !(p[i] == 1 && p[i + 1] == n)) {
        counterclockwise = false;
        break;
      }
    }
    if (n > 1 && (p[n - 1] - 1 != p[0] && !(p[n - 1] == 1 && p[0] == n))) {
        counterclockwise = false;
    }

    if (clockwise || counterclockwise) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}