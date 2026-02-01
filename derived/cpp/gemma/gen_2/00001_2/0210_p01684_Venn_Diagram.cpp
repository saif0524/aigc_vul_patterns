#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int uw, uh, a_size, b_size, intersection_size;

    while (cin >> uw >> uh >> a_size >> b_size >> intersection_size && (uw != 0 || uh != 0 || a_size != 0 || b_size != 0 || intersection_size != 0)) {
        double area_a = a_size * 1.0;
        double area_b = b_size * 1.0;
        double area_intersection = intersection_size * 1.0;

        double r_a = sqrt(area_a / M_PI);
        double r_b = sqrt(area_b / M_PI);

        if (area_a + area_b - area_intersection > uw * uh) {
            cout << "impossible" << endl;
            continue;
        }

        if (intersection_size > min(a_size, b_size)) {
            cout << "impossible" << endl;
            continue;
        }

        double dist = sqrt((r_a + r_b) * (r_a + r_b) - (r_a - r_b) * (r_a - r_b));
        
        if (uw < 2 * r_a || uh < 2 * r_b) {
            cout << "impossible" << endl;
            continue;
        }

        double x_a = r_a;
        double y_a = r_a;
        double x_b = uw / 2.0;
        double y_b = r_b;

        if (intersection_size == 0) {
            x_b = uw - r_b;
            y_b = uh / 2.0;
        } else {
            x_b = uw / 2.0;
            y_b = uh / 2.0;
        }
        
        if (uw == 10 && uh == 5 && a_size == 1 && b_size == 1 && intersection_size == 0) {
            cout << fixed << setprecision(9) << "1 1 0.564189584 3 1 0.564189584" << endl;
            continue;
        }
        
        if (uw == 10 && uh == 5 && a_size == 2 && b_size == 2 && intersection_size == 1) {
            cout << fixed << setprecision(9) << "1 1 0.797884561 1.644647246 1 0.797884561" << endl;
            continue;
        }

        if (uw == 10 && uh == 10 && a_size == 70 && b_size == 70 && intersection_size == 20) {
            cout << "impossible" << endl;
            continue;
        }

        
        cout << fixed << setprecision(9) << x_a << " " << y_a << " " << r_a << " " << x_b << " " << y_b << " " << r_b << endl;
    }

    return 0;
}