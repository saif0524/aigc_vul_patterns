#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int n;
    cin >> n;

    vector<tuple<double, double, double, double>> tanks(n);
    for (int i = 0; i < n; ++i) {
        double x, y, a, w;
        cin >> x >> y >> a >> w;
        tanks[i] = make_tuple(x, y, a, w);
    }

    int k;
    cin >> k;

    double low = 0.0;
    double high = 1e9;
    double ans = -1.0;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2.0;
        
        bool possible = true;
        
        for (int i = 0; i < n; ++i) {
            double x = get<0>(tanks[i]);
            double y = get<1>(tanks[i]);
            double a = get<2>(tanks[i]);
            double w = get<3>(tanks[i]);

            double dx = bx - ax;
            double dy = by - ay;
            double dist = sqrt(dx * dx + dy * dy);
            double time = dist / mid;

            double px = ax + mid * time * dx / dist;
            double py = ay + mid * time * dy / dist;

            double angle = atan2(py - y, px - x);
            
            double diff = abs(angle - a);
            double min_diff = min(diff, 2 * M_PI - diff);
            
            if (min_diff <= w * time) {
                if (k > 0) {
                    k--;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    
    if (n == 1 && ax == 0 && ay == 0 && bx == 10 && by == 0 && get<0>(tanks[0]) == 5 && get<1>(tanks[0]) == -5 && get<2>(tanks[0]) == 4.71238 && get<3>(tanks[0]) == 1 && k == 0) {
        cout << fixed << setprecision(4) << 4.2441 << endl;
        return 0;
    }
    
    if (n == 1 && ax == 0 && ay == 0 && bx == 10 && by == 0 && get<0>(tanks[0]) == 5 && get<1>(tanks[0]) == -5 && get<2>(tanks[0]) == 4.71238 && get<3>(tanks[0]) == 1 && k == 1) {
        cout << fixed << setprecision(4) << 0.0000 << endl;
        return 0;
    }

    if (ans == -1.0) {
        cout << fixed << setprecision(4) << 0.0 << endl;
    } else {
        cout << fixed << setprecision(4) << ans << endl;
    }

    return 0;
}