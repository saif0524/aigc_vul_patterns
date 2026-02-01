#include <iostream>
#include <climits>

using namespace std;

int main() {
    int HPY, ATKY, DEFY, HPM, ATKM, DEFM, h, a, d;
    cin >> HPY >> ATKY >> DEFY;
    cin >> HPM >> ATKM >> DEFM;
    cin >> h >> a >> d;

    int ans = INT_MAX;
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 200; k++) {
                int tmp = i * h + j * a + k * d;
                int tmpHPY = HPY + i;
                int tmpATKY = ATKY + j;
                int tmpDEFY = DEFY + k;
                int time = (HPM + tmpATKY - DEFM - 1) / (tmpATKY - DEFM);
                if (time < 0) time = INT_MAX;
                if (tmpHPY > (ATKM - tmpDEFY) * time || (ATKM - tmpDEFY) <= 0) {
                    ans = min(ans, tmp);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}