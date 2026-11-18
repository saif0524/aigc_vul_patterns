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
int main() {
  ((void)0);
  long long n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  map<int, int> m;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    m[a[i]]++;
  }
  for (size_t i = 0; i <= m[100]; i++) {
    for (size_t j = 0; j <= m[200]; j++) {
      if (i * 100 + j * 200 == sum - (i * 100 + j * 200)) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}