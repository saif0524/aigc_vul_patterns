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
  int m[5], w[5], h[2], score[5] = {500, 1000, 1500, 2000, 2500};
  for (int i = 0; i < 5; i++) cin >> m[i];
  for (int i = 0; i < 5; i++) cin >> w[i];
  cin >> h[0] >> h[1];
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int mx = (3 * score[i]) / 10;
    int cx = (((250 - m[i]) * (score[i] / 250))) - 50 * w[i];
    ans += max(mx, cx);
  }
  ans += 100 * h[0] - 50 * h[1];
  cout << ans << endl;
  return 0;
}