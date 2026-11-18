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
int arr[505000], ans;
void updata(int l, int r) {
  int i = l + 1, j = r - 1;
  while (i <= j) {
    arr[i] = arr[l];
    arr[j] = arr[r];
    i++, j--;
  }
  ans = max(ans, (r - l) / 2);
}
int main() {
  int n;
  scanf("%d", &n);
  ans = 0;
  int st = 0, ed = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (i) {
      if (arr[i] != arr[i - 1])
        ed++;
      else {
        updata(st, ed);
        st = i;
        ed = i;
      }
    }
  }
  updata(st, ed);
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
  return 0;
}