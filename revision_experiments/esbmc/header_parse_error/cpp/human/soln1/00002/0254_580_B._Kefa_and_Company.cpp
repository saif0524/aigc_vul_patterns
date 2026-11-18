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
const long long INF = 1e18;
const int MAXN = 100000 + 1000;
struct node {
  long long m, s;
  bool operator<(const node& b) const { return m < b.m; }
} num[MAXN];
long long sum[MAXN];
long long M[MAXN];
int n, d;
int main() {
  while (scanf("%d%d", &n, &d) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &num[i].m, &num[i].s);
    sort(num + 1, num + n + 1);
    sum[0] = 0;
    M[0] = 0;
    for (int i = 1; i <= n; i++) M[i] = num[i].m;
    M[n + 1] = INF;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + num[i].s;
    sum[n + 1] = sum[n];
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
      int s = i - 1;
      int e = ((long long)upper_bound(M + 1, M + n + 2,
                                      (long long)M[i] + (long long)d - 1) -
               (long long)(M + 1)) /
              sizeof(long long);
      long long temp = sum[e] - sum[s];
      ans = max(ans, temp);
    }
    printf("%I64d\n", ans);
  }
}