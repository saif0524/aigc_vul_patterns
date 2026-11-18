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
struct man {
  long long int m, s, I;
};
man a[131072];
bool cmp(man a, man b) {
  if (a.m < b.m) return true;
  if (a.m > b.m) return false;
  if (a.I > b.I) return true;
  if (a.I < b.I) return false;
}
int main() {
  queue<man> x;
  long long int n, d, i, tbr = 0, maxbr = 0;
  cin >> n >> d;
  for (i = 0; i < n; i++) {
    cin >> a[i].m >> a[i].s;
    a[i].I = i;
  }
  sort(a, a + n, cmp);
  for (i = 0; i < n; i++) {
    x.push(a[i]);
    struct man m = x.front(), m2 = x.back();
    while (m2.m - m.m >= d) {
      tbr -= m.s;
      x.pop();
      m = x.front();
      m2 = x.back();
    }
    tbr += m2.s;
    if (tbr > maxbr) maxbr = tbr;
  }
  cout << maxbr << endl;
  return 0;
}