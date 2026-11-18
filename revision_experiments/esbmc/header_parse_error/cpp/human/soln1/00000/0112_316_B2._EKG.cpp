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
int s[5555], b[5555];
bool mark[5555], moze[5555];
int main() {
  int n, x, i, j, t, q, br, of, bb;
  scanf("%d%d", &n, &x);
  for (i = 0; i <= n; i++) mark[i] = false;
  for (i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    mark[s[i]] = true;
  }
  br = 0;
  of = 0;
  q = -1;
  for (i = 1; i <= n; i++) {
    if (!mark[i]) {
      t = i;
      bb = 0;
      b[br] = 0;
      while (t != 0) {
        b[br]++;
        if (bb) of++;
        if (t == x) {
          of++;
          bb = 1;
        }
        t = s[t];
      }
      if (bb) q = br;
      br++;
    }
  }
  for (i = 0; i <= 1555; i++) moze[i] = false;
  moze[of] = true;
  for (i = 0; i < br; i++)
    if (i != q) {
      for (j = 1234; j > b[i]; j--)
        if (moze[j - b[i]]) moze[j] = true;
    }
  for (i = 1; i <= 1234; i++)
    if (moze[i]) printf("%d\n", i);
  return 0;
}