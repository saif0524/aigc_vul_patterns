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
const double Pi = acos(-1.0);
using namespace std;
const int maxN = 100005;
const long long inf = (long long)1e15;
int n;
long long b[maxN];
long long k[maxN];
long long req[maxN];
vector<int> G[maxN];
void dfs(int cur) {
  for (int i = 0; i < (int)G[cur].size(); i++) {
    int nxt = G[cur][i];
    dfs(nxt);
    if (req[nxt] < 0) {
      if (inf / k[nxt] < (-req[nxt])) {
        puts("NO");
        exit(0);
      }
      req[cur] += k[nxt] * req[nxt];
    } else
      req[cur] += req[nxt];
  }
}
int main(int argc, char** argv) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  long long a;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a);
    req[i] = b[i] - a;
  }
  int x;
  for (int i = 2; i <= n; i++) {
    scanf("%d %lld", &x, &k[i]);
    G[x].push_back(i);
  }
  dfs(1);
  puts((req[1] < 0) ? "NO" : "YES");
  return 0;
}