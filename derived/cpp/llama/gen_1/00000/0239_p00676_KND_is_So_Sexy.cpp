#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, l, x;
    while (cin >> a >> l >> x) {
        double h = sqrt(l * l - (a / 2.0) * (a / 2.0));
        double s1 = 0.5 * a * h;
        double s2 = 0;
        double x2 = x * x;
        double a2 = a * a;
        double l2 = l * l;
        double h2 = h * h;
        double t = sqrt((l2 - (a2 / 4.0)) * (x2 - (a2 / 4.0)));
        double p = (x2 - (a2 / 4.0)) / (2.0 * sqrt(l2 - (a2 / 4.0)));
        double q = x - p;
        double r = (a / 2.0) * (a / 2.0) + p * p - 2.0 * (a / 2.0) * p;
        double s = (a / 2.0) * (a / 2.0) + q * q - 2.0 * (a / 2.0) * q;
        double area = 0.5 * sqrt((l2 - (a2 / 4.0))) * (sqrt(r) + sqrt(s));
        double s2 Alternative = t * (a / 2.0);
        if (area < s2 Alternative) area = s2 Alternative;
        printf("%.10f\n", s1 + area);
    }
    return 0;
}