#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double uw, uh, a, b, c;
    while (cin >> uw >> uh >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0 && uw == 0 && uh == 0) break;

        double ra = sqrt(a / M_PI);
        double rb = sqrt(b / M_PI);

        double dist = sqrt(((a - c) / M_PI) + ((b - c) / M_PI));

        if (ra + rb + 0.0002 > min(uw, uh) || max(ra, rb) + 0.0001 > uw / 2 || max(ra, rb) + 0.0001 > uh / 2 
            || dist + 0.0002 > uw || ((a / M_PI) + (b / M_PI) - (c / M_PI)) * 2 > uw * uh) {
            cout << "impossible" << endl;
        } else {
            cout << fixed << setprecision(9);
            if (dist < uw - 2 * max(ra, rb) - 0.0002) {
                cout << (uw - dist) / 2 << " " << uh / 2 << " " << ra << " " << (uw + dist) / 2 << " " << uh / 2 << " " << rb << endl;
            } else {
                cout << uw / 2 << " " << uh - rb << " " << ra << " " << uw / 2 << " " << rb << " " << rb << endl;
            }
        }
    }
}