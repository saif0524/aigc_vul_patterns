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
int n, l;
vector<int> v;
int main() {
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x >= l) v.push_back(x);
  }
  sort(v.begin(), v.end());
  int ms = 0;
  for (int i = 0; i < v.size(); i++) {
    int count = 0;
    for (int j = i; j < v.size(); j++) count += v[j] / v[i];
    ms = max(ms, v[i] * count);
  }
  int count = 0;
  for (int j = 0; j < v.size(); j++) count += v[j] / l;
  ms = max(ms, l * count);
  printf("%d", ms);
  return 0;
}