#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-6;

int main() {
    int uw, uh, a, b, c;
    while (cin >> uw >> uh >> a >> b >> c) {
        if (uw == 0 && uh == 0 && a == 0 && b == 0 && c == 0) {
            break;
        }

        double ra = sqrt(a / M_PI);
        double rb = sqrt(b / M_PI);
        double rc = sqrt(c / M_PI);

        if (rc > min(ra, rb) || max(ra, rb) > min(uw, uh) / 2 || max(ra, rb) + min(ra, rb) > sqrt(uw * uw + uh * uh) + EPS) {
            cout << "impossible" << endl;
        } else {
            if (uw < uh) {
                swap(uw, uh);
            }
            double xa = uw / 2;
            double ya = ra;
            double xb = uw / 2;
            double yb = uh - rb;
            cout << fixed << setprecision(9) << xa << " " << ya << " " << ra << " " << xb << " " << yb << " " << rb << endl;
        }
    }

    return 0;
}