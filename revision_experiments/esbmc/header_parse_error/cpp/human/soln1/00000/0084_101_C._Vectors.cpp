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
long long ax, ay, bx, by, cx, cy;
long long AX[4], AY[4], CX[4], CY[4];
bool judge_51nod(long long ax, long long ay, long long cx, long long cy) {
  long long zi1 = abs((bx - ax) * cx + (by - ay) * cy);
  long long zi2 = abs((by - ay) * cx - (bx - ax) * cy);
  long long mu = abs(cx * cx + cy * cy);
  if (mu)
    if (zi1 % mu || zi2 % mu) return 0;
  return 1;
}
bool judge(long long ax, long long ay, long long cx, long long cy) {
  if (cx == 0 && cy == 0) return ax == bx && ay == by;
  long long zi1 = abs((bx - ax) * cx + (by - ay) * cy);
  long long zi2 = abs((by - ay) * cx - (bx - ax) * cy);
  long long mu = abs(cx * cx + cy * cy);
  return zi1 % mu == 0 && zi2 % mu == 0;
}
int main() {
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  AX[0] = ax, AY[0] = ay;
  AX[1] = -ay, AY[1] = ax;
  AX[2] = -ax, AY[2] = -ay;
  AX[3] = ay, AY[3] = -ax;
  CX[0] = cx, CY[0] = cy;
  CX[1] = -cy, CY[1] = cx;
  CX[2] = -cx, CY[2] = -cy;
  CX[3] = cy, CY[3] = -cx;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (judge(AX[i], AY[i], CX[j], CY[j])) return cout << "YES", 0;
  cout << "NO";
}