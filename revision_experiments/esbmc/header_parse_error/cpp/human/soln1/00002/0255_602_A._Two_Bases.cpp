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
  int n, bn;
  cin >> n >> bn;
  long long int sum = 0;
  while (n--) {
    int a;
    cin >> a;
    sum = (long long int)bn * sum + a;
  }
  long long int sum1 = 0;
  int m, bm;
  cin >> m >> bm;
  while (m--) {
    int a;
    cin >> a;
    sum1 = (long long int)bm * sum1 + a;
  }
  if (sum > sum1)
    cout << '>';
  else if (sum < sum1)
    cout << '<';
  else
    cout << '=';
}