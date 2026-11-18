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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n;
vector<int> num;
int mem[705][705][3];
bool solve(int a, int b, int pdir) {
  if (a >= b) return true;
  if (~mem[a][b][pdir]) return mem[a][b][pdir];
  bool ret = false;
  for (int i = a; i < b && !ret; i++) {
    if (!pdir || pdir == -1 && gcd(num[a - 1], num[i]) > 1 ||
        pdir == 1 && gcd(num[b], num[i]) > 1)
      ret = ret || (solve(a, i, 1) && solve(i + 1, b, -1));
  }
  return mem[a][b][pdir] = ret;
}
int main() {
  ((void)0), ((void)0);
  memset(mem, -1, sizeof mem);
  cin >> n;
  num.resize(n);
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num.begin(), num.end());
  cout << (solve(0, n, 0) ? "Yes" : "No") << endl;
}