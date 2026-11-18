#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double crossProduct(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        Point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        if (cin.fail()) break;
        
        double cross1 = crossProduct(A, B, C);
        double cross2 = crossProduct(B, C, D);
        double cross3 = crossProduct(C, D, A);
        double cross4 = crossProduct(D, A, B);
        
        bool convex = (cross1 >=0&& cross2 >=0&& cross3 >=0&& cross4 >= 0) ||
                     (cross1 <=0&& cross2 <=0&& cross3 <=0&& cross4 <= 0);
        
        cout << (convex ? "YES" : "NO") << "\n";
    }
    return 0;
}