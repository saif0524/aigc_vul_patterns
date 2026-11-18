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
  int i, j, n, m, k, p, s = 0;
  char A[100][100], B[100][100];
  cin >> n;
  cin >> m;
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++) {
      cin >> A[i][j];
      B[i][j] = A[i][j];
    }
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++) {
      for (k = 0; k <= m - 1; k++)
        if ((A[i][k] == A[i][j]) && (k != j) && (A[i][j] != '0')) {
          A[i][k] = '0';
          s++;
        }
      if (s > 0) A[i][j] = '0';
      s = 0;
    }
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++) {
      for (p = 0; p <= n - 1; p++)
        if ((B[p][j] == B[i][j]) && (p != i) && (B[i][j] != '0')) {
          B[p][j] = '0';
          s++;
        }
      if (s > 0) B[i][j] = '0';
      s = 0;
    }
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++)
      if ((A[i][j] != '0') && (B[i][j] != '0')) cout << A[i][j];
}