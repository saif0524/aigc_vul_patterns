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
  int N;
  cin >> N;
  int t, c;
  vector<int> T(N - 1);
  vector<int> C(N - 1);
  cin >> t;
  int a = t;
  for (int i = 0; i < N - 1; i++) {
    int b;
    cin >> b;
    T[i] = abs(b - a);
    a = b;
  }
  cin >> c;
  int w = c;
  for (int i = 0; i < N - 1; i++) {
    int b;
    cin >> b;
    C[i] = abs(w - b);
    w = b;
  }
  if (c != t || a != w) {
    cout << "No";
  } else {
    sort(T.begin(), T.end());
    sort(C.begin(), C.end());
    for (int i = 0; i < N - 1; i++) {
      if (C[i] != T[i]) {
        cout << "No";
        return 0;
      }
    }
    cout << "Yes";
  }
  return 0;
}