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

const int MAXN = 55;
int H, W;
double mA1, mA2, mB1, mB2, mX;
char grid[MAXN][MAXN];
int cntA, cntB, cntX;
double sumX, sumY;

double calc(double a, double b, double c, double d) {
    double area = (b - a) * (d - c);
    if (area ==0) return 0;
    double centerX = (a + b) / 2;
    double centerY = (c + d) / 2;
    double totalMass = cntA * (a + b) / 2 + cntB * (c + d) / 2 + cntX * mX;
    double cx = (sumX + cntA * centerX + cntB * centerX + cntX * centerX) / totalMass;
    double cy = (sumY + cntA * centerY + cntB * centerY + cntX * centerY) / totalMass;
    int x = floor(cx), y = floor(cy);
    if (grid[y][x] != '.') return area;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W;
    cin >> mA1 >> mA2 >> mB1 >> mB2 >> mX;
    for(int i=0;i<H;i++){
        cin >> grid[i];
    }
    cntA = cntB = cntX =0;
    sumX = sumY = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(grid[i][j] == 'A'){
                cntA++;
                sumX += j + 0.5;
                sumY += i + 0.5;
            }
            else if(grid[i][j] == 'B'){
                cntB++;
                sumX += j + 0.5;
                sumY += i + 0.5;
            }
            else if(grid[i][j] == 'X'){
                cntX++;
                sumX += j + 0.5;
                sumY += i + 0.5;
            }
        }
    }
    double ans = 0;
    for(double ma=mA1;ma<=mA2;ma+=0.001){
        for(double mb=mB1;mb<=mB2;mb+=0.001){
            ans += calc(ma, ma+0.001, mb, mb+0.001);
        }
    }
    ans /= (mA2 - mA1) / 0.001 * (mB2 - mB1) / 0.001;
    cout << fixed << setprecision(15) << ans << "\n";
    return 0;
}