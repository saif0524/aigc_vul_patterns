#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

double crossProduct(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

string solve(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd) {
    double abX = xb - xa;
    double abY = yb - ya;
    double acX = xc - xa;
    double acY = yc - ya;
    double adX = xd - xa;
    double adY = yd - ya;

    double bcX = xc - xb;
    double bcY = yc - yb;
    double bdX = xd - xb;
    double bdY = yd - yb;

    double cdX = xd - xc;
    double cdY = yd - yc;
    double caX = xa - xc;
    double caY = ya - yc;

    double dbX = xb - xd;
    double dbY = yb - yd;
    double daX = xa - xd;
    double daY = ya - yd;

    if (crossProduct(abX, abY, acX, acY) * crossProduct(abX, abY, adX, adY) > 0) return "NO";
    if (crossProduct(bcX, bcY, bdX, bdY) * crossProduct(bcX, bcY, caX, caY) > 0) return "NO";
    if (crossProduct(cdX, cdY, caX, caY) * crossProduct(cdX, cdY, dbX, dbY) > 0) return "NO";
    if (crossProduct(dbX, dbY, daX, daY) * crossProduct(dbX, dbY, bdX, bdY) > 0) return "NO";

    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        double xa, ya, xb, yb, xc, yc, xd, yd;
        if (!(cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd)) break;

        cout << solve(xa, ya, xb, yb, xc, yc, xd, yd) << '\n';
    }

    return 0;
}