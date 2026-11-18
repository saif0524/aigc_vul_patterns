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
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  for (int k = 2; k <= n; k++) {
    int r = (n + k - 1) / k;
    vector<int> q(n);
    for (int i = 0; i < r; i++) {
      int start = i * k;
      int end = min(start + k, n);
      for (int j = start + 1; j < end; j++) {
        q[j - 1] = p[j];
      }
      q[end - 1] = p[start];
    }
    p = q;
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  return 0;
}