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
const int INF = 0x3f3f3f3f;
int dfs(int cur, const vector<int>& ks, vector<int>& step) {
  if (ks[cur] == -1) {
    return 0;
  }
  if (step[cur] != -1) {
    return step[cur];
  }
  return step[cur] = dfs(ks[cur], ks, step) + 1;
}
int main() {
  int n;
  cin >> n;
  vector<int> ns(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ns[i]);
  }
  vector<int> ks(n, -1);
  vector<int> step(n, 0);
  for (int i = 1; i < n; i++) {
    bool flag = true;
    int cur = i - 1;
    int maxi = 0;
    while (cur >= 0 && ns[cur] < ns[i]) {
      if (ks[cur] == -1) {
        flag = false;
        break;
      }
      maxi = max(maxi, step[cur]);
      cur = ks[cur];
    }
    if (flag) {
      step[i] = maxi + 1;
    }
    ks[i] = cur;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, step[i]);
  }
  cout << ans << endl;
  return 0;
}