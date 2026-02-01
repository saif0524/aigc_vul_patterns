#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

inline double sqr(double x) { return x * x; }

bool cmp(const pair<double, double>& a, const pair<double, double>& b) {
    return a.first < b.first;
}

const double eps = 1e-13;

int main() {
    double ax, ay, bx, by, xi, yi, ai, wi;
    int n, k;

    cin >> ax >> ay >> bx >> by >> n;

    vector<pair<double, double>> t;
    for (int i = 0; i < n; ++i) {
        cin >> xi >> yi >> ai >> wi;
        double dx = xi - ax;
        double dy = yi - ay;
        double db = bx - ax;
        double db2 = sqr(bx - ax) + sqr(by - ay);
        double t1 = ai - atan2(dy, dx);
        double omega = wi;
        if (t1 < 0) t1 += 2 * M_PI;
        if (t1 > M_PI) {
            t1 = 2 * M_PI - t1;
            omega = -omega;
        }
        double d = db * ((dy * bx - dx * by) / db2);
        double tt = t1 / omega;
        double v = sqrt(sqr(d) + sqr(dx)) / (tt + eps);
        t.push_back(make_pair(v, -omega));
        tt = (M_PI - t1) / omega;
        v = sqrt(sqr(d) + sqr(dx)) / (tt + eps);
        t.push_back(make_pair(v, omega));
    }

    cin >> k;

    if (k >= n) {
        cout << "0.0000" << endl;
        return 0;
    }

    sort(t.begin(), t.end(), cmp);

    int cnt = 0;
    double v = 0;
    for (auto it : t) {
        if (cnt < k) {
            v = it.first;
            cnt++;
        } else {
            if (it.second < 0) break;
            else v = it.first;
        }
    }
    cout << fixed;
    cout.precision(4);
    cout << v << endl;

   !cin;

    return 0;
}