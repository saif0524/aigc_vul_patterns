#include <bits/stdc++.h>
using namespace std;

const int MAX = 55;

int H, W;
double mA1, mA2, mB1, mB2, mX;
char grid[MAX][MAX];
double probA, probB;
double sumX, sumY, sumMass;

void calculate(const double& ma, const double& mb) {
    sumX = sumY = sumMass = 0.0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            double mass = 0.0;
            if (grid[i][j] == 'A') mass = ma;
            else if (grid[i][j] == 'B') mass = mb;
            else if (grid[i][j] == 'X') mass = mX;
            else continue;
            sumX += mass * (j + 0.5);
            sumY += mass * (i + 0.5);
            sumMass += mass;
        }
    }
}

double check() {
    if (sumMass == 0.0) return 0.0;
    double centerX = sumX / sumMass;
    double centerY = sumY / sumMass;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.' || (j + 0.5 != centerX || i + 0.5 != centerY)) continue;
            return 1.0;
        }
    }
    return 0.0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W >> mA1 >> mA2 >> mB1 >> mB2 >> mX;
    for(int i = 0; i < H; i++){
        cin >> grid[i];
    }
    double step = 0.001;
    double ans = 0.0;
    for(double ma = mA1; ma <= mA2; ma += step){
        for(double mb = mB1; mb <= mB2; mb += step){
            calculate(ma, mb);
            ans += check() * step * step;
        }
    }
    ans /= (mA2 - mA1) / step * (mB2 - mB1) / step;
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}