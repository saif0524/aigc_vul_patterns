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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) v.push_back({b[i], a[i]});
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int k = 0, t = 0;
  while (!v.empty()) {
    k++;
    int cur = v[0].first;
    int poured = 0;
    v.erase(v.begin());
    while (!v.empty() && poured < cur) {
      if (v[0].second + poured <= cur) {
        t += v[0].second;
        poured += v[0].second;
        v.erase(v.begin());
      } else {
        t += cur - poured;
        v[0].second -= (cur - poured);
        poured = cur;
      }
    }
  }
  cout << k << " " << t << endl;
  return 0;
}