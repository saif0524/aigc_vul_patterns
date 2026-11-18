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
typedef long long ll;
const int N = 105;
int n, k, f[N], w[N];
ll s[N], mn[N];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    ll mn = 1e18;
    int x = i;
    for (int j = 0; j < k; j++) {
      sum += w[x];
      mn = min(mn, (ll)w[x]);
      x = f[x];
    }
    cout << sum << " " << mn << endl;
  }
  return 0;
}