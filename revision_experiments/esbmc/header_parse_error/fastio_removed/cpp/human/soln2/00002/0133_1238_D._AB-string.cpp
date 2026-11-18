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
  ((void)0);
  long long n, ans;
  cin >> n;
  ans = (n * (n - 1)) >> 1;
  string s;
  cin >> s;
  vector<int> A, B;
  for (int i = 0; i < int(n); i++) {
    if (s[i] == 'A')
      A.push_back(i);
    else
      B.push_back(i);
  }
  for (int i = 0; i < int(n - 1); i++) {
    if (s[i] == 'A') {
      if (s[i + 1] == 'A') {
        auto it = lower_bound(B.begin(), B.end(), i + 1);
        if (it != B.end()) ans--;
      } else {
        for (int j = i + 1; j < n && s[j] == 'B'; j++) ans--;
      }
    } else {
      if (s[i + 1] == 'A') {
        for (int j = i + 1; j < n && s[j] == 'A'; j++) ans--;
      } else {
        auto it = lower_bound(A.begin(), A.end(), i + 1);
        if (it != A.end()) ans--;
      }
    }
  }
  cout << ans << endl;
}