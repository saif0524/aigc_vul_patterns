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
  int n, m, k, kol = 0;
  char z;
  cin >> n >> m >> k;
  int qr[n + 2][m + 2][k + 2];
  for (int j = 0; j <= m + 1; j++)
    for (int q = 0; q <= k + 1; q++) {
      qr[0][j][q] = 0;
      qr[n + 1][j][q] = 0;
    }
  for (int i = 0; i <= n + 1; i++)
    for (int q = 0; q <= k + 1; q++) {
      qr[i][0][q] = 0;
      qr[i][m + 1][q] = 0;
    }
  for (int j = 0; j <= m + 1; j++)
    for (int i = 0; i <= n + 1; i++) {
      qr[i][j][0] = 0;
      qr[i][j][k + 1] = 0;
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int q = 1; q <= k; q++) {
        cin >> z;
        while ((z != '0') && (z != '1')) {
          cin >> z;
        }
        if (z == '1') {
          qr[i][j][q] = 1;
        } else
          qr[i][j][q] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int q = 1; q <= k; q++) {
        if (qr[i][j][q] == 0) continue;
        if (((qr[i + 1][j][q] == 1) && (qr[i - 1][j][q] == 1)) ||
            ((qr[i][j - 1][q] == 1) && (qr[i][j + 1][q] == 1)) ||
            ((qr[i][j][q - 1] == 1) && (qr[i][j][q + 1] == 1)) ||
            ((qr[i - 1][j][q] == 1) && (qr[i][j + 1][q] == 1) &&
             (qr[i - 1][j + 1][q] == 0)) ||
            ((qr[i - 1][j][q] == 1) && (qr[i][j][q + 1] == 1) &&
             (qr[i - 1][j][q + 1] == 0)) ||
            ((qr[i][j - 1][q] == 1) && (qr[i + 1][j][q] == 1) &&
             (qr[i + 1][j - 1][q] == 0)) ||
            ((qr[i][j - 1][q] == 1) && (qr[i][j][q + 1] == 1) &&
             (qr[i][j - 1][q + 1] == 0)) ||
            ((qr[i][j][q - 1] == 1) && (qr[i + 1][j][q] == 1) &&
             (qr[i + 1][j][q - 1] == 0)) ||
            ((qr[i][j][q - 1] == 1) && (qr[i][j + 1][q] == 1) &&
             (qr[i][j + 1][q - 1] == 0))) {
          kol++;
        }
      }
    }
  }
  cout << kol << endl;
  return 0;
}