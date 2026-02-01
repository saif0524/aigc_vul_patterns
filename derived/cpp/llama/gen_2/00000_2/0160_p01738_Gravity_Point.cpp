#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    double ma1, ma2, mb1, mb2, mx;
    cin >> ma1 >> ma2 >> mb1 >> mb2 >> mx;

    vector<string> grid(h);
    for (auto& row : grid) {
        cin >> row;
    }

    double totalA = 0, totalB = 0, totalX = 0;
    double sumA = 0, sumB = 0, sumX = 0;
    double sumAy = 0, sumBy = 0, sumXy = 0;
    double sumAx = 0, sumBx = 0, sumXx = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'A') {
                totalA += 1;
                sumA += ma1 + (ma2 - ma1) * (j + 0.5) / (w + 1) + (i + 0.5) / (h + 1);
                sumAy += (i + 0.5);
                sumAx += (j + 0.5);
            } else if (grid[i][j] == 'B') {
                totalB += 1;
                sumB += mb1 + (mb2 - mb1) * (j + 0.5) / (w + 1) + (i + 0.5) / (h + 1);
                sumBy += (i + 0.5);
                sumBx += (j + 0.5);
            } else if (grid[i][j] == 'X') {
                totalX += 1;
                sumX += mx;
                sumXy += (i + 0.5);
                sumXx += (j + 0.5);
            }
        }
    }

    if (totalA == 0 || totalB == 0 || totalX == 0) {
        cout << 0.0 << endl;
        return 0;
    }

    double xy = (sumAy + sumBy + sumXy) / (totalA + totalB + totalX);
    double xx = (sumAx + sumBx + sumXx) / (totalA + totalB + totalX);

    double fa = totalA * (ma2 - ma1) / (w + 1);
    double fb = totalB * (mb2 - mb1) / (w + 1);

    double ans = 0;
    if (fa + fb == 0) {
        cout << 1.0 << endl;
        return 0;
    }

    int points = 10000;
    double former = -1;
    double latter = -1;
    double step = 0.00001;

    for (int i = 0; i < points; i++) {
        double maa = ma1 + (ma2 - ma1) * i / (points - 1.0);
        for (int j = 0; j < points; j++) {
            double mbb = mb1 + (mb2 - mb1) * j / (points - 1.0);
            double y = (maa * totalA * sumAy + mbb * totalB * sumBy + sumXy * totalX) / (maa * totalA + mbb * totalB + totalX * mx);
            double x = (maa * totalA * sumAx + mbb * totalB * sumBx + sumXx * totalX) / (maa * totalA + mbb * totalB + totalX * mx);

            for (int k = 0; k < h; ++k) {
                for (int l = 0; l < w; ++l) {
                    if (grid[k][l] != '.') {
                        double dx = l + 0.5 - x;
                        double dy = k + 0.5 - y;

                        if (abs(dx) < 0.000001 || abs(dy) < 0.000001) continue;
                    }
                }
            }

            if (i == 0 && j == 0) {
                former = maa * totalA * sumAx + mbb * totalB * sumBx + sumXx * totalX;
                latter = maa * totalA * sumAx + mbb * totalB * sumAx + sumAx * totalX;
            } else {
                if (former != -1 && latter != -1) {
                    if (former - latter < 0) ans += 1.0 / (points * points);
                    else ans += 0;
                }

                former = maa * totalA * sumAx + mbb * totalB * sumBx + sumXx * totalX;
                latter = maa * totalA * sumAx + mbb * totalB * sumAx + sumAx * totalX;
            }
        }
    }

    cout << fixed;
    cout.precision(15);
    cout << ans << endl;

    return 0;
}