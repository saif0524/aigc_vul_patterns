#include <bits/stdc++.h>
using namespace std;

int H, W;
int mA1, mA2, mB1, mB2, mX;
char grid[55][55];
double mAx, mAy, mT;

void calc(int x, int y, double ma, double mb, double mx) {
    double m = 0, cx = 0, cy = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'A') {
                m += ma;
                cx += ma * (i + 0.5);
                cy += ma * (j + 0.5);
            } else if (grid[i][j] == 'B') {
                m += mb;
                cx += mb * (i + 0.5);
                cy += mb * (j + 0.5);
            } else if (grid[i][j] == 'X') {
                m += mx;
                cx += mx * (i + 0.5);
                cy += mx * (j + 0.5);
            }
        }
    }
    if (m > 0) {
        double nx = cx / m, ny = cy / m;
        if (floor(nx) != nx && floor(ny) != ny) {
            int ix = (int)nx, jx = (int)ny;
            if (grid[ix][jx] != '.') {
                mAx += ma;
                mAy += mb;
                mT += mx;
            }
        }
    }
}

int main(){
    cin >> H >> W;
    cin >> mA1 >> mA2 >> mB1 >> mB2 >> mX;
    for(int i = 0; i < H; i++) cin >> grid[i];
    for(double ma = mA1; ma <= mA2; ma += 0.001) {
        for(double mb = mB1; mb <= mB2; mb += 0.001) {
            calc(0, 0, ma, mb, mX);
        }
    }
    double delta = 0.001 * 0.001;
    cout << fixed << setprecision(15) << (mAx + mAy + mT) / (mA2 - mA1 + delta) / (mB2 - mB1 + delta) << endl;
}