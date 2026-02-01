#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    long long l, r, d;
    cin >> l >> r >> d;

    long long x = d;
    while (x >= l && x <= r) {
      x += d;
    }
    cout << x << endl;
  }

  return 0;
}