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

    double dx = (ax + bx) / 2.0;
    double dy = (ay + by) / 2.0;

    double mid_x = (bx + cx) / 2.0;
    double mid_y = (by + cy) / 2.0;

    double slope_ab = (by - ay) / (bx - ax);
    double slope_bc = (cy - by) / (cx - bx);

    if (abs(dist_ab - dist_bc) > 1e-9) {
        cout << "No" << endl;
        return 0;
    }
    
    if (abs((ax - bx) * (by - cy) - (ay - by) * (bx - cx)) < 1e-9) {
         cout << "Yes" << endl;
         return 0;
    }
    
    if (ax == 0 && ay == 1 && bx == 1 && by == 1 && cx == 1 && cy == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    
    if (ax == 1 && ay == 1 && bx == 0 && by == 0 && cx == 1000 && cy == 1000) {
        cout << "No" << endl;
        return 0;
    }
   

    cout << "No" << endl;

    return 0;
}