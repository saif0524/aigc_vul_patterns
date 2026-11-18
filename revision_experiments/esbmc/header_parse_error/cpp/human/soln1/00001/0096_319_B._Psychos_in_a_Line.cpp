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
int n, m[100005], x, k[100005], res, last;
stack<int> s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (s.empty() || x > s.top()) {
      s.push(x);
    } else {
      if (last > x) {
        m[x] = 1;
        k[x] = last;
      } else {
        int lastVic = last;
        while (k[lastVic] < x || m[k[lastVic]] == m[lastVic]) {
          lastVic = k[lastVic];
        }
        m[x] = m[lastVic] + 1;
        k[x] = k[lastVic];
      }
    }
    res = max(res, m[x]);
    last = x;
  }
  cout << res << endl;
  return 0;
}