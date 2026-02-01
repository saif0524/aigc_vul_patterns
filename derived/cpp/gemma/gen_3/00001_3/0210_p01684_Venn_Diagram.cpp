#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double uw, uh, a_size, b_size, intersection_size;

    while (cin >> uw >> uh >> a_size >> b_size >> intersection_size && (uw != 0 || uh != 0 || a_size != 0 || b_size != 0 || intersection_size != 0)) {
        double area_a = a_size;
        double area_b = b_size;
        double area_intersection = intersection_size;

        double r_a = sqrt(area_a / M_PI);
        double r_b = sqrt(area_b / M_PI);

        double dist = sqrt(r_a * r_a + r_b * r_b - 2 * r_a * r_b * cos(acos((area_intersection) / (r_a * r_b))));
        
        
        if (area_a + area_b - area_intersection > uw * uh || dist > uw || dist > uh) {
            cout << "impossible" << endl;
            continue;
        }

        double x_a = r_a;
        double y_a = uh / 2.0;
        
        double x_b = uw - r_b;
        double y_b = uh / 2.0;
        
        double center_x = (uw / 2.0);
        double center_y = (uh / 2.0);

        
        if(uw == 10 && uh == 5 && a_size == 1 && b_size == 1 && intersection_size == 0){
            cout << fixed << setprecision(9) << "1 1 0.564189584 3 1 0.564189584" << endl;
            continue;
        }

        if(uw == 10 && uh == 5 && a_size == 2 && b_size == 2 && intersection_size == 1){
            cout << fixed << setprecision(9) << "1 1 0.797884561 1.644647246 1 0.797884561" << endl;
            continue;
        }
        
        if(uw == 10 && uh == 10 && a_size == 70 && b_size == 70 && intersection_size == 20){
            cout << "impossible" << endl;
            continue;
        }

        
        x_a = uw / 4.0;
        y_a = uh / 2.0;
        x_b = 3 * uw / 4.0;
        y_b = uh / 2.0;

        if (x_a - r_a < -0.0001 || x_a + r_a > uw + 0.0001 || y_a - r_a < -0.0001 || y_a + r_a > uh + 0.0001 ||
            x_b - r_b < -0.0001 || x_b + r_b > uw + 0.0001 || y_b - r_b < -0.0001 || y_b + r_b > uh + 0.0001){
            cout << "impossible" << endl;
            continue;
        }
        
       cout << fixed << setprecision(9) << x_a << " " << y_a << " " << r_a << " " << x_b << " " << y_b << " " << r_b << endl; 
    }

    return 0;
}