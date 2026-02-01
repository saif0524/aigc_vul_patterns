#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;

    double maxVal = -1e10;
    string maxExpr;

    string expr[12] = {
        to_string(x) + "^" + to_string(y) + "^" + to_string(z),
        to_string(x) + "^" + to_string(z) + "^" + to_string(y),
        "(" + to_string(x) + "^" + to_string(y) + ")^" + to_string(z),
        "(" + to_string(x) + "^" + to_string(z) + ")^" + to_string(y),
        to_string(y) + "^" + to_string(x) + "^" + to_string(z),
        to_string(y) + "^" + to_string(z) + "^" + to_string(x),
        "(" + to_string(y) + "^" + to_string(x) + ")^" + to_string(z),
        "(" + to_string(y) + "^" + to_string(z) + ")^" + to_string(x),
        to_string(z) + "^" + to_string(x) + "^" + to_string(y),
        to_string(z) + "^" + to_string(y) + "^" + to_string(x),
        "(" + to_string(z) + "^" + to_string(x) + ")^" + to_string(y),
        "(" + to_string(z) + "^" + to_string(y) + ")^" + to_string(x)
    };

    double vals[12] = {
        x * y * z,
        x * z * y,
        pow(x * y, z),
        pow(x * z, y),
        y * x * z,
        y * z * x,
        pow(y * x, z),
        pow(y * z, x),
        z * x * y,
        z * y * x,
        pow(z * x, y),
        pow(z * y, x)
    };

    for(int i = 0; i < 12; i++) {
        if(vals[i] > maxVal) {
            maxVal = vals[i];
            maxExpr = expr[i];
        }
    }

    cout << maxExpr << endl;

    return 0;
}