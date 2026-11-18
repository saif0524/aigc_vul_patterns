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
typedef pair<ll, ll> pii;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast_io ((void)0); ((void)0); ((void)0);

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  fast_io;
  int n;
  cin >> n;
  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(all(v), [](pii a, pii b) {
    return a.second < b.second;
  });
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i].first;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (sum - v[i].first) * v[i].second;
    sum -= v[i].first;
  }
  ll g = gcd(ans, sum);
  cout << ans / g << " " << sum / g << endl;
  return 0;
}