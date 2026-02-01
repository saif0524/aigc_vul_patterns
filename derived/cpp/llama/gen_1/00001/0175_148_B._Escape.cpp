#include <iostream>
using namespace std;

int main() {
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    int ans = 0;
    double cur_dist = t * vp;
    while (cur_dist < c) {
        double time_to_catch = cur_dist / (vd - vp);
        double dist_when_catch = cur_dist + time_to_catch * vp;
        if (dist_when_catch >= c) {
            break;
        }
        ans++;
        cur_dist = dist_when_catch + (f + dist_when_catch / vd) * vp;
    }
    cout << ans << endl;

    return 0;
}