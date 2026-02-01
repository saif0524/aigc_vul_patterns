#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    double dist_ab = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
    double dist_bc = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));

    if (dist_ab == 0 || dist_bc == 0) {
        cout << "No" << endl;
        return 0;
    }

    if (abs(dist_ab - dist_bc) < 1e-9) {
        cout << "Yes" << endl;
        return 0;
    }

    double mid_x = (ax + bx + cx) / 3.0;
    double mid_y = (ay + by + cy) / 3.0;

    double dx1 = ax - mid_x;
    double dy1 = ay - mid_y;
    double dx2 = bx - mid_x;
    double dy2 = by - mid_y;
    double dx3 = cx - mid_x;
    double dy3 = cy - mid_y;
    
    
    if (abs(dx1*dx2 + dy1*dy2) < 1e-9 && abs(dx2*dx3 + dy2*dy3) < 1e-9) {
        cout << "Yes" << endl;
        return 0;
    }

    
    double cross_product = (bx - ax) * (cy - by) - (by - ay) * (cx - bx);

    if (abs(cross_product) < 1e-9) {
        cout << "No" << endl;
        return 0;
    }

    
    if (abs(dist_ab - dist_bc) < 1e-9) {
        cout << "Yes" << endl;
        return 0;
    }
  

    cout << "No" << endl;

    return 0;
}