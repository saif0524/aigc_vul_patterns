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
const int MAXN = 2e5 + 100;
int n, k;
vector<pair<int, int> > a[MAXN];
int main(void) {
  ((void)0);
  ((void)0);
  cout << fixed << setprecision(15);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    a[l].push_back({r, i});
  }
  set<pair<int, int> > st;
  vector<int> res;
  for (int i = 1; i < MAXN; i++) {
    while (st.size() > 0 and st.begin()->first < i) st.erase(st.begin());
    for (auto& p : a[i]) { st.insert(p); }
    while (st.size() > k) {
      auto last = --st.end();
      res.push_back(last->second);
      st.erase(last);
    }
  }
  sort(res.begin(), res.end());
  cout << res.size() << "\n";
  for (int x : res) { cout << x << " "; }
  cout << "\n";
  return 0;
}