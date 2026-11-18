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
const long long MX = 5e5 + 3;
long long T;
int32_t main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> T;
  for (long long w = 0; w < T; w++) {
    long long n, m, cnt = 0;
    cin >> n >> m;
    set<long long> st, edg;
    for (long long i = 0; i < m; i++) {
      long long u, v;
      cin >> u >> v;
      if (cnt < n && st.find(u) == st.end() && st.find(v) == st.end()) {
        edg.insert(i);
        cnt++;
        st.insert(u);
        st.insert(v);
      }
    }
    if (cnt == n) {
      cout << "Matching" << endl;
      for (auto u : edg) cout << u + 1 << " ";
      cout << endl;
    } else {
      cout << "IndSet" << endl;
      cnt = 0;
      for (long long i = 1; i < n * 3 + 1; i++)
        if (cnt < n && st.find(i) == st.end()) cout << i << " ", cnt++;
      cout << endl;
    }
  }
  return 0;
}