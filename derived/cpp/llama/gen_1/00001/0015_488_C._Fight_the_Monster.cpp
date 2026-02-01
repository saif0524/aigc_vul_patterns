#include <iostream>
#include <climits>

using namespace std;

int main() {
    int HPY, ATKY, DEFY;
    int HPM, ATKM, DEFM;
    int h, a, d;

    cin >> HPY >> ATKY >> DEFY;
    cin >> HPM >> ATKM >> DEFM;
    cin >> h >> a >> d;

    int ans = INT_MAX;

    for (int i = 0; i <= 100 * 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                int ny = HPY + i;
                int na = ATKY + j;
                int nd = DEFY + k;

                int tm = (HPM + max(0, nd - ATKM) - 1) / max(0, na - DEFM);
                int ty = (ny + max(0, DEFM - na) - 1) / max(0, ATKM - nd);

                if (tm < ty) {
                    ans = min(ans, i * h + j * a + k * d);
                }
            }
        }
    }

    if (HPY > HPM && ATKY >= DEFM && DEFY >= ATKM) {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}