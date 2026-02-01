#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool check_constraints(double x, double y, double r, int uw, int uh) {
    return (x - r >= -0.0001 && x + r <= uw + 0.0001 &&
            y - r >= -0.0001 && y + r <= uh + 0.0001);
}

int main() {
    int uw, uh, a, b, ab;
    while (cin >> uw >> uh >> a >> b >> ab && (uw || uh || a || b || ab)) {
        double area_a = a - ab;
        double area_b = b - ab;
        double area_ab = ab;
        
        if (area_a < 0 || area_b < 0 || area_ab < 0) {
            cout << "impossible" << endl;
            continue;
        }
        
        double r_a = sqrt(area_a / M_PI);
        double r_b = sqrt(area_b / M_PI);
        double r_ab = sqrt(area_ab / M_PI);
        
        double x_a, y_a, x_b, y_b;
        if (area_a == 0 && area_b == 0) {
            x_a = uw / 2.0;
            y_a = uh / 2.0;
            r_a = 0;
            x_b = uw / 2.0;
            y_b = uh / 2.0;
            r_b = 0;
        } else if (area_a == 0) {
            x_a = uw / 2.0;
            y_a = uh / 2.0;
            r_a = 0;
            x_b = uw / 2.0;
            y_b = uh / 2.0;
            r_b = r_ab + r_b;
        } else if (area_b == 0) {
            x_a = uw / 2.0;
            y_a = uh / 2.0;
            r_a = r_ab + r_a;
            x_b = uw / 2.0;
            y_b = uh / 2.0;
            r_b = 0;
        } else {
            double d = sqrt(r_a * r_a + r_b * r_b - 2 * r_a * r_b * cos(M_PI / 2.0 - acos((r_a * r_a + d * d - r_b * r_b) / (2 * r_a * d))));
            x_a = (uw - d) / 2.0 + r_a;
            y_a = uh / 2.0;
            x_b = (uw + d) / 2.0 - r_b;
            y_b = uh / 2.0;
        }
        
        if (check_constraints(x_a, y_a, r_a, uw, uh) && check_constraints(x_b, y_b, r_b, uw, uh)) {
            cout << fixed << setprecision(9) << x_a << ' ' << y_a << ' ' << r_a << ' ' << x_b << ' ' << y_b << ' ' << r_b << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}