#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-8;

struct Tank {
    double x, y, a, w;
};

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double angle(double x, double y) {
    return atan2(y, x);
}

double timeToAim(double a, double w, double targetAngle) {
    double diff = targetAngle - a;
    if (diff < -M_PI) diff += 2 * M_PI;
    if (diff > M_PI) diff -= 2 * M_PI;
    if (diff > 0) return diff / w;
    else return -diff / w;
}

int main() {
    double ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int n;
    cin >> n;
    vector<Tank> tanks(n);
    for (int i = 0; i < n; i++) {
        cin >> tanks[i].x >> tanks[i].y >> tanks[i].a >> tanks[i].w;
    }
    int k;
    cin >> k;

    double abLen = dist(ax, ay, bx, by);
    vector<double> times;
    for (int i = 0; i < n; i++) {
        double t1 = timeToAim(tanks[i].a, tanks[i].w, angle(tanks[i].x - ax, tanks[i].y - ay));
        double t2 = timeToAim(tanks[i].a, tanks[i].w, angle(tanks[i].x - bx, tanks[i].y - by));
        if (t1 < t2) {
            double t = t1;
            double x = ax + (bx - ax) * t / abLen;
            double y = ay + (by - ay) * t / abLen;
            double distToTank = dist(tanks[i].x, tanks[i].y, x, y);
            times.push_back(distToTank / t);
        }
    }
    sort(times.begin(), times.end());
    if (k >= n) {
        cout << fixed << setprecision(4) << 0.0 << endl;
    } else {
        cout << fixed << setprecision(4) << times[k] << endl;
    }
    return 0;
}