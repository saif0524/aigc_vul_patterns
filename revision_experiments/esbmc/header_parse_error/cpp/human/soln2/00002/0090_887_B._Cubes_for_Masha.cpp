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
int a[10][10];
int num[200];
int vis[10];
int tot;
void dfs(int sumn, int tt) {
  if (tt > 2) return;
  num[sumn]++;
  for (int i = 1; i <= tot; i++) {
    if (vis[i] == 0) {
      vis[i] = 1;
      for (int j = 1; j <= 6; j++) {
        dfs(sumn * 10 + a[i][j], tt + 1);
      }
      vis[i] = 0;
    }
  }
}
int main() {
  while (cin >> tot) {
    for (int i = 1; i <= tot; i++) {
      for (int j = 1; j <= 6; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(num, 0, sizeof(num));
    memset(vis, 0, sizeof(vis));
    dfs(0, 0);
    for (int i = 0; i <= 99; i++) {
      if (num[i] == 0) {
        printf("%d\n", i - 1);
        break;
      }
    }
  }
  return 0;
}