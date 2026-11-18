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
int T;
int n, m;
char s[200043];
int p[200043];
long long cnt[200043];
long long ans[43];
int main(int argc, char const *argv[]) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 0; i < m; ++i) {
      scanf("%d", &p[i]);
      --p[i];
    }
    sort(p, p + m);
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    int del = 0;
    int sci = 0;
    for (int i = 0; i < n; ++i) {
      cnt[i] += (long long)m - del;
      while (i == p[sci] && sci < m) {
        ++sci;
        ++del;
      }
    }
    for (int i = 0; i < n; ++i) ans[s[i] - 'a'] += cnt[i] + 1;
    for (int i = 0; i < 26; ++i) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}