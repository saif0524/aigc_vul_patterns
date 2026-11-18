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
const int INF = 1e9;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int n, k;
  cin >> n >> k;
  vector<int> alice, bobo, osdois;
  for (int i = 0; i < n; i++) {
    bool a, b;
    int t;
    cin >> t >> a >> b;
    if (a and b) {
      osdois.push_back(t);
    } else if (a) {
      alice.push_back(t);
    } else if (b) {
      bobo.push_back(t);
    }
  }
  sort(alice.begin(), alice.end());
  sort(bobo.begin(), bobo.end());
  sort(osdois.begin(), osdois.end());
  queue<int> al, bb, ab;
  for (auto num : alice) { al.push(num); }
  for (auto num : bobo) { bb.push(num); }
  for (auto num : osdois) { ab.push(num); }
  int ans = 0;
  int cont = 0;
  while (cont < k) {
    if (ab.empty()) {
      if (bb.empty() or al.empty()) break;
      ans += bb.front();
      ans += al.front();
      bb.pop();
      al.pop();
      cont++;
      continue;
    }
    if (al.empty() or bb.empty()) {
      ans += ab.front();
      cont++;
      ab.pop();
    } else {
      if (al.front() + bb.front() < ab.front()) {
        ans += al.front() + bb.front();
        al.pop();
        bb.pop();
        cont++;
      } else {
        ans += ab.front();
        cont++;
        ab.pop();
      }
    }
  }
  if (cont != k) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}