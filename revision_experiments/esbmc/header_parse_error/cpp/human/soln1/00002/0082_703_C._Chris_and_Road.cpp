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
int N;
long double W, B, P;
pair<long double, long double> bus[10001];
bool win = true;
long double ans;
int main() {
  ios_base::sync_with_stdio(false);
  if (fopen("cf703c.in", "r")) {
    freopen("cf703c.in", "r", stdin);
    freopen("cf703c.out", "w", stdout);
  }
  cin >> N >> W >> B >> P;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    bus[i].first = a * 1.0;
    bus[i].second = b * 1.0;
    if (bus[i].first * P < bus[i].second * B) {
      win = false;
    }
    ans = max(ans, max(bus[i].first / B, bus[i].second / P) +
                       (W - bus[i].second) / P);
  }
  if (win) {
    cout << fixed << setprecision(20) << W / P << '\n';
    return 0;
  } else {
    cout << fixed << setprecision(20) << ans << '\n';
    return 0;
  }
}