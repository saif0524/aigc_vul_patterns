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
int main() {
  int a[3][3];
  for (int i = 0; i <= 2; i++)
    for (int j = 0; j <= 2; j++) cin >> a[i][j];
  for (int i = 1; i <= 100000; i++) {
    a[0][0] = i;
    int s = a[0][0] + a[1][0] + a[2][0];
    a[1][1] = s - a[0][1] - a[2][1];
    if (a[1][1] <= 0) continue;
    a[2][2] = s - a[1][1] - a[0][0];
    if (a[2][2] <= 0) continue;
    int y = 0;
    for (int i = 0; i <= 2; i++) {
      if (a[i][0] + a[i][1] + a[i][2] != s) y = 1;
      if (a[0][i] + a[1][i] + a[2][i] != s) y = 1;
    }
    if (y) continue;
    if (a[0][0] + a[1][1] + a[2][2] != s) continue;
    if (a[0][2] + a[1][1] + a[2][0] != s) continue;
    for (int i = 0; i <= 2; i++) {
      for (int j = 0; j <= 2; j++) cout << a[i][j] << ' ';
      cout << endl;
    }
    return 0;
  }
}