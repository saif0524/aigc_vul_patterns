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

void solve() {
  int n;
  cin >> n;
  vector<int> k(n), l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> k.at(i) >> l.at(i) >> r.at(i);
  }
  int64_t s = 0;
  vector<pair<int, int>> al, ar;
  for (int i = 0; i < n; i++) {
    s += min(l.at(i), r.at(i));
    if (l.at(i) > r.at(i)) {
      al.emplace_back(k.at(i), max(l.at(i), r.at(i)) - min(l.at(i), r.at(i)));
    } else {
      ar.emplace_back(n - k.at(i), max(l.at(i), r.at(i)) - min(l.at(i), r.at(i)));
    }
  }
  sort(al.rbegin(), al.rend());
  sort(ar.rbegin(), ar.rend());
  priority_queue<int> q;
  int64_t ans = s;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < al.size() and al.at(j).first == n - i) {
      q.push(al.at(j).second);
      j++;
    }
    if (q.empty()) continue;
    ans += q.top();
    q.pop();
  }
  while (!q.empty()) {
    q.pop();
  }
  j = 0;
  for (int i = 0; i < n; i++) {
    while (j < ar.size() and ar.at(j).first == n - i) {
      q.push(ar.at(j).second);
      j++;
    }
    if (q.empty()) continue;
    ans += q.top();
    q.pop();
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}