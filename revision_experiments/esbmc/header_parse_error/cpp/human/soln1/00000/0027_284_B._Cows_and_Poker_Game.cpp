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
template <class T>
void pp(T v) {
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
    cout << *it << ' ';
  cout << endl;
}
template <class T>
void pp(T v, int n) {
  for (int i = 0; i < (int)n; i++) cout << v[i] << ' ';
  cout << endl;
}
template <class T>
inline void chmax(T &a, const T b) {
  a = max(a, b);
}
template <class T>
inline void chmin(T &a, const T b) {
  a = min(a, b);
}
const int INF = 1 << 28;
const double EPS = 1.0e-9;
static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int main(void) {
  int N;
  cin >> N;
  string line;
  cin >> line;
  int A = 0, F = 0, I = 0;
  for (int i = 0; i < (int)N; i++) {
    switch (line[i]) {
      case 'A':
        A++;
        break;
      case 'F':
        F++;
        break;
      case 'I':
        I++;
        break;
    }
  }
  int ans = 0;
  for (int i = 0; i < (int)N; i++) {
    if (line[i] == 'A' || line[i] == 'I') {
      int irem = I - (line[i] == 'I' ? 1 : 0);
      if (irem <= 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}