#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int l, r, d;
    cin >> l >> r >> d;

    int x = d;
    while (x >= l && x <= r) {
      x += d;
    }
    cout << x << endl;
  }

  return 0;
}