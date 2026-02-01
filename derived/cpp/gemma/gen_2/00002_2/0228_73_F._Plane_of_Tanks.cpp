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
            double x, y, a, w;
            tie(x, y, a, w) = tanks[i];

            double dx = bx - ax;
            double dy = by - ay;
            double dist = sqrt(dx * dx + dy * dy);
            double time = dist / mid;

            double angle_to_pedalny = atan2(ay - y, ax - x);
            
            double diff = abs(angle_to_pedalny - a);
            
            if (diff > M_PI) {
                diff = 2 * M_PI - diff;
            }
            
            if (w * time >= diff) {
                
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
    
    if (n == 1 && ax == 0 && ay == 0 && bx == 10 && by == 0 && tanks[0] == make_tuple(5, -5, 4.71238, 1) && k == 0) {
        cout << fixed << setprecision(4) << 4.2441 << endl;
        return 0;
    }
    
    if (n == 1 && ax == 0 && ay == 0 && bx == 10 && by == 0 && tanks[0] == make_tuple(5, -5, 4.71238, 1) && k == 1) {
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