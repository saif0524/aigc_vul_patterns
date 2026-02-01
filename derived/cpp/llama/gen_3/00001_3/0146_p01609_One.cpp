#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const double EPS = 1e-6;

struct Point {
    double x, y;
};

struct Parabola {
    double a, p, q;
};

double calcY(const Parabola& para, double x) {
    return para.a * (x - para.p) * (x - para.p) + para.q;
}

double calcX(const Parabola& para, double y) {
    return para.p + sqrt((y - para.q) / para.a);
}

double calcX2(const Parabola& para, double y) {
    return para.p - sqrt((y - para.q) / para.a);
}

double calcLength(const Parabola& para, double x1, double x2) {
    double y1 = calcY(para, x1);
    double y2 = calcY(para, x2);
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<Parabola> paras(N);
    for (int i = 0; i < N; i++) {
        cin >> paras[i].a >> paras[i].p >> paras[i].q;
    }

    double ans = 0.0;
    for (int i = 0; i < N; i++) {
        double x1 = max(0.0, calcX2(paras[i], 0.0));
        double x2 = min(W, calcX(paras[i], 0.0));
        if (x1 < x2) {
            ans += calcLength(paras[i], x1, x2);
        }
    }

    cout << fixed;
    cout.precision(20);
    cout << ans << endl;

    return 0;
}