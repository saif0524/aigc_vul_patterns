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
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  long long arr[m];
  for (long long i = 0; i < m; i++) cin >> arr[i];
  long long ans = 0;
  long long sub = 0;
  long long g = 1, temp;
  long long now = (arr[0] - 1) / k;
  ;
  for (long long i = 1; i < m; i++) {
    temp = (arr[i] - 1 - sub) / k;
    if (now == temp)
      g++;
    else {
      sub += g;
      g = 1;
      temp = (arr[i] - 1 - sub) / k;
      now = temp;
      ans++;
    }
  }
  cout << ans + 1;
}