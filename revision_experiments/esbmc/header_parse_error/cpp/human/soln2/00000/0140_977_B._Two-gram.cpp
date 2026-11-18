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
const int MOD = 998244353;
const int MAX = 200001;
int An[MAX];
int book[MAX];
int main() {
  string str;
  char a = 'a', b = 'b';
  int n;
  cin >> n >> str;
  int sum = 0;
  int mmax = 0;
  for (int i = 0; i < n - 1; i++) {
    sum = 0;
    for (int j = 0; j < n - 1; j++) {
      if (str[i] == str[j] && str[i + 1] == str[j + 1]) sum++;
    }
    if (sum > mmax) {
      mmax = sum;
      a = str[i];
      b = str[i + 1];
    }
  }
  cout << a << b << endl;
  return 0;
}