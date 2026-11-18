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
char a[2345][2345];
int d[2345][2345];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int main() {
  int n, m, i, j, k;
  cin >> n >> m >> k;
  string s = "ULRD";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (j = 1; j <= m; j++) {
    int d = 0;
    for (i = 1; i <= n; i++) {
      int t = (i - 1);
      for (k = 0; k < 4; k++) {
        int x = i + dx[k] * t;
        int y = j + dy[k] * t;
        if (x >= 1 && x <= n && y <= m && y >= 1 && a[x][y] == s[k]) d++;
      }
    }
    cout << d << " ";
  }
}