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
const long long int inf = 1000000000000000LL;
int main() {
  ((void)0);
  ((void)0);
  long long int n, m;
  long long int k;
  cin >> n >> m >> k;
  vector<long long int> a(m);
  for (int j = 0; j < m; j++) cin >> a[j];
  long long int i = 0, ans = 0;
  long long int sum = 0, pag = 1ll;
  if (a[0] % k == 0) {
    pag = a[0] / k;
  } else
    pag = a[0] / k + 1;
  while (i < m) {
    if ((a[i] - sum) <= k * pag) {
      int cont = 0;
      while (i < m && (a[i] - sum) <= k * pag) {
        i++;
        cont++;
        if (i == m) break;
      }
      sum += cont;
      ans++;
    } else {
      if ((a[i] - sum) % k == 0) {
        pag = (a[i] - sum) / k;
      } else {
        pag = (a[i] - sum) / k + 1;
      }
    }
  }
  cout << ans;
  return 0;
}