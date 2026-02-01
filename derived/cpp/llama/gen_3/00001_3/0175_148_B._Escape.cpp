#include <iostream>
#include <cmath>

int main() {
    double vp, vd, t, f, c;
    std::cin >> vp >> vd >> t >> f >> c;

    double x = vp * t;
    double ans = 0;

    while (x < c) {
        if (vd * (x / (vd - vp)) + f * (ans + 1) + (c - x) / vd > c / vp) {
            ans++;
            x += (vd * (x / (vd - vp))) * (vp / vd);
        } else {
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}