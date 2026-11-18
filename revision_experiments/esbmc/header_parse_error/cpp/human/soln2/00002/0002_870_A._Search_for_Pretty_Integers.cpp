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
  int n, m;
  cin >> n >> m;
  vector<int> vec;
  vector<int> arr(10, 100);
  vector<int> arr2(10, 100);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    arr[a] = a;
  }
  for (int i = 1; i <= m; i++) {
    int a;
    cin >> a;
    arr2[a] = a;
    if (arr[a] == a) vec.push_back(a);
  }
  if (vec.size()) {
    sort(vec.begin(), vec.end());
    cout << vec.front();
    return 0;
  }
  sort(&arr[0], &arr[10]);
  sort(&arr2[0], &arr2[10]);
  int a = arr[0], b = arr2[0];
  cout << min(a, b) << max(a, b);
  return 0;
}