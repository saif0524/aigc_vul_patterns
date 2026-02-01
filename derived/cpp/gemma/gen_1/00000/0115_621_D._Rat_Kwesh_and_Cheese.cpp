#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;

    double a1 = pow(x, pow(y, z));
    double a2 = pow(x, pow(z, y));
    double a3 = pow(pow(x, y), z);
    double a4 = pow(pow(x, z), y);
    double a5 = pow(y, pow(x, z));
    double a6 = pow(y, pow(z, x));
    double a7 = pow(pow(y, x), z);
    double a8 = pow(pow(y, z), x);
    double a9 = pow(z, pow(x, y));
    double a10 = pow(z, pow(y, x));
    double a11 = pow(pow(z, x), y);
    double a12 = pow(pow(z, y), x);

    double max_val = a1;
    int max_index = 1;

    if (a2 > max_val) {
        max_val = a2;
        max_index = 2;
    }
    if (a3 > max_val) {
        max_val = a3;
        max_index = 3;
    }
    if (a4 > max_val) {
        max_val = a4;
        max_index = 4;
    }
    if (a5 > max_val) {
        max_val = a5;
        max_index = 5;
    }
    if (a6 > max_val) {
        max_val = a6;
        max_index = 6;
    }
    if (a7 > max_val) {
        max_val = a7;
        max_index = 7;
    }
    if (a8 > max_val) {
        max_val = a8;
        max_index = 8;
    }
    if (a9 > max_val) {
        max_val = a9;
        max_index = 9;
    }
    if (a10 > max_val) {
        max_val = a10;
        max_index = 10;
    }
    if (a11 > max_val) {
        max_val = a11;
        max_index = 11;
    }
    if (a12 > max_val) {
        max_val = a12;
        max_index = 12;
    }

    if (max_index == 1) {
        cout << "x^y^z" << endl;
    } else if (max_index == 2) {
        cout << "x^z^y" << endl;
    } else if (max_index == 3) {
        cout << "(x^y)^z" << endl;
    } else if (max_index == 4) {
        cout << "(x^z)^y" << endl;
    } else if (max_index == 5) {
        cout << "y^x^z" << endl;
    } else if (max_index == 6) {
        cout << "y^z^x" << endl;
    } else if (max_index == 7) {
        cout << "(y^x)^z" << endl;
    } else if (max_index == 8) {
        cout << "(y^z)^x" << endl;
    } else if (max_index == 9) {
        cout << "z^x^y" << endl;
    } else if (max_index == 10) {
        cout << "z^y^x" << endl;
    } else if (max_index == 11) {
        cout << "(z^x)^y" << endl;
    } else {
        cout << "(z^y)^x" << endl;
    }

    return 0;
}