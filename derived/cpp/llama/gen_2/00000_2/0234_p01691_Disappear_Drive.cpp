#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Circle {
    double x, y, r;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double solve(vector<Circle> &circles, int D) {
    double ans = distance(25, 0, 25, 94);
    for (int i = 0; i < circles.size(); i++) {
        double dist1 = distance(25, 0, circles[i].x, circles[i].y);
        double dist2 = distance(circles[i].x, circles[i].y, 25, 94);
        double dist = dist1 + dist2;
        if (dist < ans) {
            ans = dist;
            if (D > 0) {
                for (int j = 0; j < circles.size(); j++) {
                    if (i != j) {
                        double dist3 = distance(25, 0, circles[j].x, circles[j].y);
                        double dist4 = distance(circles[j].x, circles[j].y, 25, 94);
                        double dist5 = distance(circles[i].x, circles[i].y, circles[j].x, circles[j].y);
                        double dist6 = dist3 + dist5 + dist4;
                        if (dist6 < ans) {
                            ans = dist6;
                        }
                    }
                }
            }
        }
    }
    if (ans == distance(25, 0, 25, 94)) {
        if (D == 0) {
            return -1;
        }
    }
    return ans;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<Circle> circles(N);
    for (int i = 0; i < N; i++) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
    cout << fixed;
    cout.precision(10);
    cout << solve(circles, D) << endl;
    return 0;
}