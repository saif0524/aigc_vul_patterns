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
using ll = signed long long int;
const int N = 1e5 + 100;
int n, res;
ll mx[N], a[N], d, cv;
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n && res != -1; i++) {
    if (a[i] == 0) {
      cv = max(0LL, cv);
    } else {
      cv += a[i];
      if (cv > d) {
        res = -1;
      }
    }
  }
  if (res != -1) {
    mx[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      mx[i] = max(mx[i + 1] + a[i], a[i]);
    }
    cv = 0LL;
    for (int i = 0; i < n; i++) {
      cv += a[i];
      if (a[i] == 0LL) {
        if (cv < 0LL) {
          res++;
          cv = d - mx[i];
        }
      }
    }
  }
  cout << res;
}