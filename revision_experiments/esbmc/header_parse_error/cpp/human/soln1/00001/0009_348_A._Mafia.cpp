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
class sort_map {
 public:
  int num;
  int val;
};
bool myfunc(int a, int b) { return a > b; }
int main() {
  long long n;
  cin >> n;
  vector<long long> input;
  long long mmax = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    input.push_back(temp);
    sum += temp;
    if (temp > mmax) mmax = temp;
  }
  int e = ceil(sum / (n - 1.0));
  if (e < mmax) e = mmax;
  cout << e;
  return 0;
}