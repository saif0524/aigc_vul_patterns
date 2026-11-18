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
long long hm1, hm2, am1, am2, dm1, dm2, a, h, d, jav = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> hm1 >> am1 >> dm1;
  cin >> hm2 >> am2 >> dm2;
  cin >> h >> a >> d;
  for (int i = hm1; i < 1000; i++)
    for (int j = am1; j < 400; j++)
      for (int k = dm1; k < 200; k++) {
        if (dm2 < j) {
          long long y = 1e9;
          long long x = (hm2 + j - dm2 - 1) / (j - dm2);
          if (am2 > k) y = (i + am2 - k - 1) / (am2 - k);
          if (x < y) {
            long long p = (i - hm1) * h + (j - am1) * a + (k - dm1) * d;
            jav = min(jav, p);
          }
        }
      }
  if (jav == 1e9) jav = 0;
  cout << jav << endl;
  return 0;
}