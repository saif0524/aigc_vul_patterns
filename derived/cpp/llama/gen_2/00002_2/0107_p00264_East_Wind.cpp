#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int H, R;
int hx[105], hy[105];
int U, M, S, du, dm, ds;
int ux[15], uy[15], mx[15], my[15], sx[15], sy[15];
int w[105], a[105];
int ans[105];

bool check(int x, int y, int wx, int wa, int ox, int oy, int oa) {
    double dx = x - ox;
    double dy = y - oy;
    double angle = atan2(dy, dx);
    if (angle < 0) angle += 2 * PI;
    double dangle = fabs(angle - wx * PI / 180.0);
    if (dangle > PI) dangle = 2 * PI - dangle;
    if (dangle > wa * PI / 180.0) return false;
    double dist = sqrt(dx * dx + dy * dy);
    return dist <= wa;
}

bool check2(int x, int y, int wx, int wa, int ox, int oy, int oa) {
    double dx = x - ox;
    double dy = y - oy;
    double angle = atan2(dy, dx);
    if (angle < 0) angle += 2 * PI;
    double dangle = fabs(angle - wx * PI / 180.0);
    if (dangle > PI) dangle = 2 * PI - dangle;
    if (dangle > oa * PI / 180.0) return false;
    double dist = sqrt(dx * dx + dy * dy);
    return dist <= wa;
}

int main() {
    while (true) {
        cin >> H >> R;
        if (H == 0 && R == 0) break;
        for (int i = 1; i <= H; i++) {
            cin >> hx[i] >> hy[i];
        }
        cin >> U >> M >> S >> du >> dm >> ds;
        for (int i = 1; i <= U; i++) {
            cin >> ux[i] >> uy[i];
        }
        for (int i = 1; i <= M; i++) {
            cin >> mx[i] >> my[i];
        }
        for (int i = 1; i <= S; i++) {
            cin >> sx[i] >> sy[i];
        }
        for (int i = 1; i <= R; i++) {
            cin >> w[i] >> a[i];
        }
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= R; j++) {
                bool ok = true;
                ok &= check(hx[i], hy[i], w[j], a[j], 0, 0, du);
                for (int k = 1; k <= U; k++) {
                    if (check(hx[i], hy[i], w[j], a[j], ux[k], uy[k], du)) {
                        ok = false;
                        break;
                    }
                }
                for (int k = 1; k <= M; k++) {
                    if (check2(hx[i], hy[i], w[j], a[j], mx[k], my[k], dm)) {
                        ok = false;
                        break;
                    }
                }
                for (int k = 1; k <= S; k++) {
                    if (check2(hx[i], hy[i], w[j], a[j], sx[k], sy[k], ds)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans[i]++;
            }
        }
        int maxx = 0;
        for (int i = 1; i <= H; i++) {
            maxx = max(maxx, ans[i]);
        }
        if (maxx == 0) {
            cout << "NA" << endl;
        } else {
            for (int i = 1; i <= H; i++) {
                if (ans[i] == maxx) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}