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
  int q, x;
  cin >> q >> x;
  vector<int> a;
  for (int i = 0; i < q; i++) {
    int y;
    cin >> y;
    a.push_back(y);
    set<int> s;
    for (int j = 0; j < a.size(); j++) {
      s.insert(a[j] % x);
    }
    int mex = 0;
    while (s.find(mex) != s.end()) {
      mex++;
    }
    int ans = mex;
    for (int j = 0; j < a.size(); j++) {
      int val = a[j] / x;
      int mod = a[j] % x;
      if (mod != 0) {
        int new_val = val * x;
        if (s.find(new_val % x) == s.end()) {
          ans = max(ans, new_val + x);
        }
      } else {
        int new_val = (val + 1) * x;
        if (s.find(new_val % x) == s.end()) {
          ans = max(ans, new_val);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}