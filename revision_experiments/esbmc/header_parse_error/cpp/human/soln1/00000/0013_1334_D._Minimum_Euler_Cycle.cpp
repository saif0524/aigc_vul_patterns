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
long long n;
int tc = 0;
int solve();
int main() {
  ios_base::sync_with_stdio(0);
  if (tc < 0) {
    cout << "TC!\n";
    cin.ignore(1e8);
  } else if (!tc)
    cin >> tc;
  while (tc--) solve();
  return 0;
}
int solve() {
  long long l, r;
  cin >> n >> l >> r;
  l--;
  r--;
  long long a = 1;
  while (1) {
    if (l > 2 * (n - a)) {
      l -= 2 * (n - a);
      r -= 2 * (n - a);
      a++;
    } else
      break;
  }
  vector<long long> ans;
  int b = a + 1;
  while (ans.size() <= r + 1) {
    ans.push_back(a);
    ans.push_back(b);
    b++;
    if (b == n + 1) {
      a++;
      if (a == n) {
        ans.push_back(1);
        break;
      }
      b = a + 1;
    }
  }
  for (int i = l; i <= r; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}