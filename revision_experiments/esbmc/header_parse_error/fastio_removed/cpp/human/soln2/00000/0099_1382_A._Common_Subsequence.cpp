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
long long int sumdigit(long long int num) {
  long long int sum = 0;
  while (num) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
int main() {
  ((void)0);
  ((void)0);
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    int dp1[1002] = {0}, dp2[1002] = {0};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      dp1[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      dp2[b[i]]++;
    }
    bool ans = false;
    int value;
    for (int i = 0; i < 1002; i++) {
      if (dp1[i] > 0 && dp2[i] > 0) {
        ans = true;
        value = i;
        break;
      }
    }
    if (ans) {
      cout << "YES" << endl;
      cout << 1 << " " << value << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}