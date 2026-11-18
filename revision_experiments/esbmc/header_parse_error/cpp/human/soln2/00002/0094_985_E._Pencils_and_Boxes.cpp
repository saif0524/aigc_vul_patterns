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
const long long mod = 1e9 + 7;
const long double pi = 3.14159265358979323846264338327950288;
int main() {
  int n, k;
  long long d;
  cin >> n >> k >> d;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  queue<long long> q;
  q.push(0);
  int cnt = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == n) {
      cout << "YES" << endl;
      return 0;
    }
    cnt = max(cnt, u + k);
    while (cnt <= n && a[cnt - 1] - a[u] <= d) q.push(cnt), cnt++;
  }
  cout << "NO" << endl;
}