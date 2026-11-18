#include <bits/stdc++.h>
using namespace std;

double crossProduct(double x1, double y1, double x2, double y2, double x3, double y3) {
  return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    double xa, ya, xb, yb, xc, yc, xd, yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

    double ab = crossProduct(xa, ya, xb, yb, xc, yc);
    double bc = crossProduct(xb, yb, xc, yc, xd, yd);
    double cd = crossProduct(xc, yc, xd, yd, xa, ya);
    double da = crossProduct(xd, yd, xa, ya, xb, yb);

    if ((ab > 0 && bc > 0 && cd > 0 && da > 0) || (ab < 0 && bc < 0 && cd < 0 && da < 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}