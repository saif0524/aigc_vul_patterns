#include <iostream>
using namespace std;

int main() {
    double vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    if (vp >= vd) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    double princess_pos = vp * t;
    double dragon_pos = 0;

    while (princess_pos < c) {
        double time_to_meet = (princess_pos - dragon_pos) / (vd - vp);
        princess_pos += time_to_meet * vp;
        dragon_pos += time_to_meet * vd;
        ans++;

        if (princess_pos >= c) break;

        princess_pos += (f + dragon_pos / vd) * vp;
        dragon_pos = 0;
    }

    cout << ans << endl;

    return 0;
}