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
  ((void)0);
  ((void)0);
  int N;
  cin >> N;
  for (int TST_CASE = 1; TST_CASE <= N; TST_CASE++) {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i % 2 == 0) {
          if (j % 2 == 0) {
            if (a[i][j] % 2 == 1) a[i][j]++;
          } else {
            if (a[i][j] % 2 == 0) a[i][j]++;
          }
        } else {
          if (j % 2 == 1) {
            if (a[i][j] % 2 == 1) a[i][j]++;
          } else {
            if (a[i][j] % 2 == 0) a[i][j]++;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
  }
}