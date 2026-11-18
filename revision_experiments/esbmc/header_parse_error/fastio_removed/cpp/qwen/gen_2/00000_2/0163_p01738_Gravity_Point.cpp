// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
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
    ((void)0);
    ((void)0);
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