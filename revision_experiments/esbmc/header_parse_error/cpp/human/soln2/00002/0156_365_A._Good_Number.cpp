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
  int n, k;
  cin >> n >> k;
  int count = 0;
  while (n--) {
    int A[k + 5];
    for (int i = 0; i <= k; i++) {
      A[i] = 0;
    }
    int a;
    cin >> a;
    while (a > 0) {
      int d = a % 10;
      A[d] = 1;
      a /= 10;
    }
    int flag = 0;
    for (int i = 0; i <= k; i++) {
      if (A[i] == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      count++;
    }
  }
  cout << count;
}