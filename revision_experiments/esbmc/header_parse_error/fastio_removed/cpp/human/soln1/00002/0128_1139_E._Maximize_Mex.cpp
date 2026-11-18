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
#pragma GCC optimize("O3")
std::pair<int, int> DR[] = {{-1, 0}, {0, 1},   {1, 0}, {0, -1},
                            {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
using namespace std;
int gcd(int a, int b) {
  if (b) return gcd(b, a % b);
  return a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, viz[5005], match[5005], p[5005], c[5005], d;
vector<int> vec[5005];
bool f(int x) {
  for (auto it : vec[x]) {
    if (!viz[it]) {
      viz[it] = 1;
      if (match[it] == -1 || f(match[it])) {
        match[it] = x;
        return 1;
      }
    }
  }
  return 0;
}
int32_t main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  cin >> d;
  vector<int> vek;
  while (d--) {
    int x;
    cin >> x;
    vek.push_back(x);
  }
  reverse(vek.begin(), vek.end());
  int mex = 0;
  vector<int> ans;
  set<int> s;
  for (int i = 1; i <= n; i++) s.insert(i);
  for (auto it : vek) s.erase(s.find(it));
  for (auto it : s) vec[p[it]].push_back(c[it]);
  memset(match, -1, sizeof(match));
  for (auto it : vek) {
    while (1) {
      memset(viz, 0, sizeof(viz));
      if (f(mex))
        mex++;
      else
        break;
    }
    ans.push_back(mex);
    vec[p[it]].push_back(c[it]);
  }
  reverse(ans.begin(), ans.end());
  for (auto it : ans) cout << it << '\n';
}