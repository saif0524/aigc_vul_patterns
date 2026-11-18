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
bool vis[1000008];
int link[1000008];
void solve() {
  int a, k, i, j, n, sum = 0, mx = 0, ind, ct = 1, curr = 0, remain = -1;
  cin >> n;
  int D[n + 5];
  for (i = 0; i < n; i++) {
    cin >> D[i];
    vis[D[i]] = 1;
  }
  link[D[n - 1]] = D[n - 1];
  for (i = 0; i < n - 1; i++) {
    link[D[i]] = D[i + 1];
  }
  if (D[0] == 0) {
    while (vis[++curr])
      ;
    cout << curr << " ";
    while (vis[++curr])
      ;
    remain = 0;
  } else {
    cout << 0 << " ";
    while (vis[++curr])
      ;
  }
  for (i = 1; i < n; i++) {
    if (D[i] != D[i - 1]) {
      cout << D[i - 1] << " ";
      if (remain == D[i - 1]) remain = -1;
      continue;
    }
    if (remain != D[i] && remain > -1) {
      cout << remain << " ";
      remain = -1;
    } else {
      cout << curr << " ";
      while (vis[++curr])
        ;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}