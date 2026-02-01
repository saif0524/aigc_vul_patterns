#include <iostream>
#include <vector>
#include <complex>
using namespace std;

typedef complex<double> point;

double dot(const point& a, const point& b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

int main() {
    int n;
    cin >> n;

    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p[i] = point(x, y);
    }

    bool is_convex = true;
    int sign = 0;

    for (int i = 0; i < n; i++) {
        point a = p[(i + n - 1) % n] - p[i];
        point b = p[(i + 1) % n] - p[i];

        double cross_product = a.real() * b.imag() - a.imag() * b.real();

        if (sign == 0) {
            sign = cross_product > 0 ? 1 : -1;
            continue;
        }

        if (cross_product * sign < 0) {
            is_convex = false;
            break;
        }
    }

    cout << (is_convex ? "1" : "0") << endl;

    return 0;
}