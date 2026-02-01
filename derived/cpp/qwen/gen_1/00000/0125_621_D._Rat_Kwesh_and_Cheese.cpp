#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;

    double a1 = x * pow(y, z);
    double a2 = x * pow(z, y);
    double a3 = pow(x * y, z);
    double a4 = pow(x * z, y);
    double a5 = y * pow(x, z);
    double a6 = y * pow(z, x);
    double a7 = pow(y * x, z);
    double a8 = pow(y * z, x);
    double a9 = z * pow(x, y);
    double a10 = z * pow(y, x);
    double a11 = pow(z * x, y);
    double a12 = pow(z * y, x);

    double max_val = a1;
    string expression = "x^y^z";

    if (a2 > max_val) { max_val = a2; expression = "x^z^y"; }
    if (a3 > max_val) { max_val = a3; expression = "(x^y)^z"; }
    if (a4 > max_val) { max_val = a4; expression = "(x^z)^y"; }
    if (a5 > max_val) { max_val = a5; expression = "y^x^z"; }
    if (a6 > max_val) { max_val = a6; expression = "y^z^x"; }
    if (a7 > max_val) { max_val = a7; expression = "(y^x)^z"; }
    if (a8 > max_val) { max_val = a8; expression = "(y^z)^x"; }
    if (a9 > max_val) { max_val = a9; expression = "z^x^y"; }
    if (a10 > max_val) { max_val = a10; expression = "z^y^x"; }
    if (a11 > max_val) { max_val = a11; expression = "(z^x)^y"; }
    if (a12 > max_val) { max_val = a12; expression = "(z^y)^x"; }

    cout << expression << endl;

    return 0;
}