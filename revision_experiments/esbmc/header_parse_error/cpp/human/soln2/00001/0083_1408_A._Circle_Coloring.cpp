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
int T, N;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    vector<int> a(N), b(N), c(N), ans(N, -1);
    for (int n = 0; n < N; n++) cin >> a[n];
    for (int n = 0; n < N; n++) cin >> b[n];
    for (int n = 0; n < N; n++) cin >> c[n];
    for (int n = 0; n < N; n++) {
      for (int j : {a[n], b[n], c[n]}) {
        if (ans[(N + n - 1) % N] != j && ans[(n + 1) % N] != j) {
          ans[n] = j;
          break;
        }
      }
    }
    for (int n = 0; n < N; n++) printf("%d ", ans[n]);
    printf("\n");
  }
}