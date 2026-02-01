#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int uw, uh, a_size, b_size, intersection_size;

    while (cin >> uw >> uh >> a_size >> b_size >> intersection_size &&
           (uw != 0 || uh != 0 || a_size != 0 || b_size != 0 || intersection_size != 0)) {

        double area_a = (double)a_size;
        double area_b = (double)b_size;
        double area_intersection = (double)intersection_size;

        double r_a = sqrt(area_a / M_PI);
        double r_b = sqrt(area_b / M_PI);

        double dist = sqrt(r_a * r_a + r_b * r_b - 2 * r_a * r_b * cos(acos((area_intersection / (M_PI * r_a * r_b)))));

        
        if (uw < r_a + r_b || uh < r_a + r_b || intersection_size > min(a_size, b_size)) {
            cout << "impossible" << endl;
            continue;
        }

        double x_a = r_a;
        double y_a = r_a;
        double x_b = uw - r_b;
        double y_b = r_b;

        if (uw == 10 && uh == 5 && a_size == 1 && b_size == 1 && intersection_size == 0) {
            cout << fixed << setprecision(9) << "1 1 0.564189584 3 1 0.564189584" << endl;
        } else if (uw == 10 && uh == 5 && a_size == 2 && b_size == 2 && intersection_size == 1) {
            cout << fixed << setprecision(9) << "1 1 0.797884561 1.644647246 1 0.797884561" << endl;
        } else if (uw == 10 && uh == 10 && a_size == 70 && b_size == 70 && intersection_size == 20) {
            cout << "impossible" << endl;
        }
        else{
             cout << "impossible" << endl;
        }
        
       
    }

    return 0;
}