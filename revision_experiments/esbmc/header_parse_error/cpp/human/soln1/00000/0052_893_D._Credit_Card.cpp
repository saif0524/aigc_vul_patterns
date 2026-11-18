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
  cout << fixed << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, d;
  cin >> n >> d;
  long long int a[n], b[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = (i ? b[i - 1] + a[i] : a[i]);
    if (b[i] > d) {
      cout << -1;
      return 0;
    }
  }
  long long int maxi[n + 1];
  maxi[n] = 0;
  maxi[n - 1] = b[n - 1];
  for (long long int i = n - 2; i >= 0; i--) maxi[i] = max(b[i], maxi[i + 1]);
  long long int added = 0, ans = 0;
  if (a[0] == 0 && b[0] < 0) {
    added += d - maxi[0];
    if (b[0] + added < 0) {
      cout << -1;
      return 0;
    }
    ++ans;
  }
  for (long long int i = 1; i < n; i++) {
    b[i] += added;
    if (a[i] == 0 && b[i] < 0) {
      long long int here = d - maxi[i] - added;
      added += here;
      ++ans;
      b[i] += here;
      if (b[i] < 0) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << ans;
}