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
const long long MAX_N = 200 * 1000 + 24;
long long n;
long long a[MAX_N], b[MAX_N], c[MAX_N], cnt[MAX_N];
set<long long> s;
int32_t main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    cnt[b[i]]++;
    if (cnt[b[i]] == 1) s.insert(b[i]);
  }
  set<long long>::iterator it;
  for (long long i = 0; i < n; i++) {
    it = s.lower_bound(n - a[i]);
    if (it == s.end()) it = s.begin();
    c[i] = (a[i] + *it) % n;
    cnt[*it]--;
    if (cnt[*it] == 0) s.erase(it);
  }
  for (long long i = 0; i < n; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
}