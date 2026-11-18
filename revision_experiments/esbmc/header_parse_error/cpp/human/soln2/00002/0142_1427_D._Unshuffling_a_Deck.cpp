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
int a[110], n;
vector<int> tmp;
vector<vector<int>> ans;
void work(const vector<int>& v) {
  int now = 1;
  for (const auto& i : v) reverse(a + now, a + now + i), now += i;
  reverse(a + 1, a + n + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n - 1; i++) {
    tmp.clear();
    for (int j = 1; j <= i - 1; j++) tmp.push_back(1);
    if (i & 1) {
      for (int j = n - i + 1; j; j--)
        if (a[j] == i) {
          tmp.push_back(n - i + 1 - j + 1);
          if (j != 1) tmp.push_back(j - 1);
        }
      reverse(tmp.begin(), tmp.end());
    } else {
      for (int j = i; j <= n; j++)
        if (a[j] == i) {
          tmp.push_back(j - i + 1);
          if (j != n) tmp.push_back(n - j);
        }
    }
    if (tmp.size() > 1) {
      ans.push_back(tmp);
      work(tmp);
    }
  }
  if (a[1] != 1) {
    tmp.clear();
    for (int i = 1; i <= n; i++) tmp.push_back(1);
    ans.push_back(tmp);
    work(tmp);
  }
  printf("%d\n", (int)ans.size());
  for (const auto& i : ans) {
    printf("%d", (int)i.size());
    for (const auto& j : i) printf(" %d", j);
    printf("\n");
  }
  return 0;
}