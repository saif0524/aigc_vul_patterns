#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double xa, ya, xb, yb, xc, yc, xd, yd;
    while (cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd) {
        double cross_ab_bc = (xb - xa) * (yc - yb) - (yb - ya) * (xc - xb);
        double cross_bc_cd = (xc - xb) * (yd - yc) - (yc - yb) * (xd - xc);
        double cross_cd_da = (xd - xc) * (ya - yd) - (yd - yc) * (xa - xd);
        double cross_da_ab = (xa - xd) * (yb - ya) - (ya - yd) * (xb - xa);

        if ((cross_ab_bc > 0 && cross_bc_cd > 0 && cross_cd_da > 0 && cross_da_ab > 0) ||
            (cross_ab_bc < 0 && cross_bc_cd < 0 && cross_cd_da < 0 && cross_da_ab < 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}