#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double xa, ya, xb, yb, xc, yc, xd, yd;
  cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

  double cross_ab_cd = (xb - xa) * (yd - yc) - (xd - xc) * (yb - ya);
  double cross_bc_da = (xc - xb) * (xa - xd) - (xa - xb) * (yc - yd);

  if ((cross_ab_cd > 0 && cross_bc_da > 0) || (cross_ab_cd < 0 && cross_bc_da < 0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}