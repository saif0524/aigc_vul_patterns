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
const int maxN = 105;
bool taken[maxN][maxN];
int main() {
  int numQueries, size;
  scanf("%i %i", &numQueries, &size);
  int xCenter = (size + 1) / 2, yCenter = (size + 1) / 2;
  for (int i = 0; i < numQueries; i++) {
    int M;
    scanf("%i", &M);
    int xc, yc, cost = -1;
    for (int x = 0; x < size; x++)
      for (int y = 0; y < size - M + 1; y++) {
        int theCost = 0;
        bool ok = true;
        for (int t = 0; t < M; t++)
          if (taken[x][y + t]) {
            ok = false;
            break;
          } else
            theCost += abs(x + 1 - xCenter) + abs(y + t + 1 - yCenter);
        if (!ok) continue;
        if (cost == -1 || theCost <= cost) {
          if (theCost == cost) {
            if (x > xc) continue;
            if (x == xc && y > yc) continue;
          }
          cost = theCost;
          xc = x;
          yc = y;
        }
      }
    if (cost == -1) {
      printf("%i\n", -1);
      continue;
    }
    for (int t = 0; t < M; t++) taken[xc][yc + t] = true;
    printf("%i %i %i\n", xc + 1, yc + 1, yc + M);
  }
  return 0;
}