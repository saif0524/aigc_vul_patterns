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
int w[505], b[1005], c[505];
bool vis[505];
int ss[505];
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (j = 1; j <= m; j++) {
    cin >> b[j];
  }
  int ret = 0, u = 0;
  stack<int> st;
  for (i = 1; i <= m; i++) {
    stack<int> q;
    while (q.size() != 0) q.pop();
    while (st.size() != 0) {
      int x = st.top();
      st.pop();
      if (x == b[i]) {
        break;
      }
      q.push(x);
    }
    while (q.size() != 0) {
      st.push(q.top());
      ret += w[q.top()];
      q.pop();
    }
    st.push(b[i]);
  }
  cout << ret << endl;
}