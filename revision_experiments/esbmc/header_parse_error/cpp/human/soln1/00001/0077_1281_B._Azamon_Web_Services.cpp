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
int caseno = 0;
void yesno(bool okk) { cout << (okk ? "YES" : "NO") << '\n'; }
const int primemod = 1000000007;
const long long maxsize = 1 * 1000000 + 9;
const double eps = 1e-10;
const int N = 210;
void solve() {
  string t, s;
  cin >> s >> t;
  if (s < t) {
    cout << s << '\n';
    return;
  }
  string temp = s;
  sort(temp.begin(), temp.end());
  for (__typeof(((s.size()) < (t.size()) ? (s.size()) : (t.size()))) i =
           (0) - ((0) > (((s.size()) < (t.size()) ? (s.size()) : (t.size()))));
       i != (((s.size()) < (t.size()) ? (s.size()) : (t.size()))) -
                ((0) > (((s.size()) < (t.size()) ? (s.size()) : (t.size()))));
       i +=
       1 - 2 * ((0) > (((s.size()) < (t.size()) ? (s.size()) : (t.size()))))) {
    if (temp[i] < s[i])
      for (__typeof(s.size()) j = (i + 1) - ((i + 1) > (s.size()));
           j != (s.size()) - ((i + 1) > (s.size()));
           j += 1 - 2 * ((i + 1) > (s.size()))) {
        swap(s[i], s[j]);
        if (s < t) {
          goto h;
        }
        swap(s[i], s[j]);
      }
  }
h:;
  if (s < t)
    cout << s << '\n';
  else
    cout << "---" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}