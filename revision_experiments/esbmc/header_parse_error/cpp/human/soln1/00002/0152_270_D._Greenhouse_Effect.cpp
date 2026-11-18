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
int xx[5002][5002];
int lon_com_sub(int *ar, int *br, int n) {
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        xx[i][j] = 0;
      else if (ar[i - 1] == br[j - 1])
        xx[i][j] = xx[i - 1][j - 1] + 1;
      else {
        if (xx[i - 1][j] > xx[i][j - 1])
          xx[i][j] = xx[i - 1][j];
        else
          xx[i][j] = xx[i][j - 1];
      }
    }
  }
  return xx[n][n];
}
int main() {
  int n, m, i, x;
  int ar[5002];
  double arr[5002];
  int br[5002];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d %lf", &ar[i], &arr[i]);
    br[i] = ar[i];
  }
  sort(br, br + n);
  x = lon_com_sub(ar, br, n);
  printf("%d\n", n - x);
  return 0;
}