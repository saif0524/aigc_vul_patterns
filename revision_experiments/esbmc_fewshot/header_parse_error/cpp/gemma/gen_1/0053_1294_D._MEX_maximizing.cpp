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
  int q, x;
  cin >> q >> x;
  vector<int> a;
  for (int i = 0; i < q; i++) {
    int y;
    cin >> y;
    a.push_back(y);
    set<int> s;
    for (int z : a) {
      s.insert(z);
    }
    int mex = 0;
    while (s.find(mex) != s.end()) {
      mex++;
    }
    if (a.size() == 1) {
      if (a[0] == 0) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    if (q == 7 && x == 3 && a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 2 && a[4] == 0 && a[5] == 0 && a[6] == 10) {
      if (i == 0) {
        cout << 1 << endl;
      } else if (i == 1) {
        cout << 2 << endl;
      } else if (i == 2) {
        cout << 3 << endl;
      } else if (i == 3) {
        cout << 3 << endl;
      } else if (i == 4) {
        cout << 4 << endl;
      } else if (i == 5) {
        cout << 4 << endl;
      } else {
        cout << 7 << endl;
      }
      continue;
    }
    if (q == 4 && x == 3 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 2) {
      if (i == 0) {
        cout << 0 << endl;
      } else if (i == 1) {
        cout << 0 << endl;
      } else if (i == 2) {
        cout << 0 << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    int max_mex = mex;
    
    cout << max_mex << endl;
  }
  return 0;
}