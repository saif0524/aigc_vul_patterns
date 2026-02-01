#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-6;

double ca, cb, cc, ra, rb;

inline double sqr(double x) {
    return x * x;
}

inline double f(double x) {
    return sqr((ca + x * ra) / 2) + sqr(cb / 2) - sqr(ra + x * rb) / 4 - sqr(x * rb) / 4;
}

inline double df(double x) {
    return (ca + x * ra) * ra / 2 - (ra + x * rb) * rb / 2 - x * sqr(rb) / 2;
}

int main() {
    int uw, uh, a, b, c;
    while (true) {
        cin >> uw >> uh >> a >> b >> c;
        if (uw == 0 && uh == 0 && a == 0 && b == 0 && c == 0) {
            break;
        }
        ra = sqrt(a / M_PI), rb = sqrt(b / M_PI);
        if (uw - ra * 2 < EPS || uh - ra * 2 < EPS || uw - rb * 2 < EPS || uh - rb * 2 < EPS) {
            cout << "impossible" << endl;
            continue;
        }
        ca = uw - ra - rb, cb = uh - max(ra, rb);
        double x = (sqrt(sqr(ca) + sqr(cb)) - ca) / cb;
        x = max(0.0, min(x, 1.0));
        if (f(x) < -EPS || fabsl(df(x)) > EPS) {
            cout << "impossible" << endl;
            continue;
        }
        double d = sqrt(sqr(ca + x * ra) + sqr(cb));
        if (fabsl(f(x)) > EPS || fabsl(d - ra - x * rb) > EPS) {
            cout << "impossible" << endl;
            continue;
        }
        cout << fixed;
        cout.precision(9);
        cout << ra + x * rb << ' ' << cb / 2 << ' ' << ra << ' ' << uw - ra - (1 - x) * rb << ' ' << cb / 2 << ' ' << rb << endl;
    }
    return 0;
}