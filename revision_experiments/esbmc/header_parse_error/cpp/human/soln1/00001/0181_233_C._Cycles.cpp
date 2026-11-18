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
int a[105][105];
int main() {
  int k;
  cin >> k;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      if (i != j) a[i][j] = 1;
  k--;
  int ans = 3;
  if (k) {
    for (ans = ans + 1; ans <= 100; ans++) {
      for (int i = 1; i < ans; i++) {
        int cnt = 0;
        for (int j = 1; j < i; j++)
          if (a[i][j] && a[j][ans]) {
            cnt++;
          }
        if (k >= cnt) {
          k -= cnt;
          a[i][ans] = a[ans][i] = 1;
        }
        if (!k) break;
      }
      if (!k) break;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) {
    for (int j = 1; j <= ans; j++) cout << a[i][j];
    cout << endl;
  }
  return 0;
}