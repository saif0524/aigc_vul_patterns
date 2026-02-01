#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double xa, ya, xb, yb, xc, yc, xd, yd;
  while (cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd) {
    double cross1 = (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa);
    double cross2 = (xc - xb) * (yd - yb) - (yc - yb) * (xd - xb);
    double cross3 = (xd - xc) * (ya - yc) - (yd - yc) * (xa - xc);
    double cross4 = (xa - xd) * (yb - yd) - (ya - yd) * (xb - xd);

    if ((cross1 > 0 && cross2 > 0 && cross3 > 0 && cross4 > 0) ||
        (cross1 < 0 && cross2 < 0 && cross3 < 0 && cross4 < 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}