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
  int n, k, b;
  scanf("%d%d%d", &n, &k, &b);
  stack<pair<int, int> > st;
  long long ans = (long long)n * b;
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    if (st.size() && st.top().first == a) {
      st.top().second++;
      if (st.top().second == k) ans -= (long long)k * b, st.pop();
    } else
      st.push({a, 1});
  }
  deque<int> q;
  while (st.size()) {
    while (st.top().second) q.push_front(st.top().first), st.top().second--;
    st.pop();
  }
  while (q.size()) {
    int c = 0, x = q.front();
    while (q.size() && q.front() == x) c++, q.pop_front();
    while (q.size() && q.back() == x) c++, q.pop_back();
    if (!q.size()) {
      long long am = (long long)b * c;
      if (am % k == 0) return puts("0"), 0;
      ans -= (am / k) * k;
    } else if (c % k == 0) {
      ans -= (long long)c * (b - 1);
    } else {
      ans -= (c / k) * k * (long long)(b - 1);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}