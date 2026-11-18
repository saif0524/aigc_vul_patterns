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
  ((void)0);
  ((void)0);
  ((void)0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n], arr1[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long maxi = *max_element(arr, arr + n);
    for (long long i = 0; i < n; i++) {
      arr[i] = maxi - arr[i];
    }
    maxi = *max_element(arr, arr + n);
    for (long long i = 0; i < n; i++) arr1[i] = maxi - arr[i];
    if (k % 2 == 1) {
      for (long long i = 0; i < n; i++) cout << arr[i] << " ";
      cout << "\n";
    } else {
      for (long long i = 0; i < n; i++) cout << arr1[i] << " ";
      cout << "\n";
    }
  }
  return 0;
}