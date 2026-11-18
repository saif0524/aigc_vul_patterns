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
long long sum[300008], record[300008], a[300008];
struct Tree {
  long long value, id;
} tree[300008];
int cmp(Tree a, Tree b) {
  if (a.value == b.value)
    return a.id < b.id;
  else
    return a.value < b.value;
}
int main() {
  long long n, i, j, ans, l = 0, r = 0, temp, num;
  sum[0] = 0;
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &tree[i].value);
    tree[i].id = i;
    sum[i] = sum[i - 1];
    a[i] = tree[i].value;
    if (tree[i].value > 0) sum[i] += tree[i].value;
  }
  sort(tree + 1, tree + n + 1, cmp);
  for (i = 1; i < n; i++)
    if (tree[i].value == tree[i + 1].value) {
      for (j = i + 2; j <= n && tree[j].value == tree[j - 1].value; j++)
        ;
      j--;
      temp = sum[tree[j].id - 1] - sum[tree[i].id] + tree[i].value * 2;
      if ((l == 0 && r == 0) || ans < temp) {
        ans = temp;
        l = tree[i].id;
        r = tree[j].id;
      }
      i = j;
    }
  num = 0;
  for (i = 1; i < l; i++) record[num++] = i;
  for (i = l + 1; i < r; i++)
    if (a[i] < 0) record[num++] = i;
  for (i = r + 1; i <= n; i++) record[num++] = i;
  printf("%I64d %I64d\n", ans, num);
  for (i = 0; i < num; i++) printf("%I64d ", record[i]);
  return 0;
}