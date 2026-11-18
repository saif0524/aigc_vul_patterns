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
bool check(int x, int y, vector<vector<char>> &v) {
  if (y <= 1) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x][y + i] == 'x') {
        cnt0++;
      } else if (v[x][y + i] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  if (x <= 1) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x + i][y] == 'x') {
        cnt0++;
      } else if (v[x + i][y] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  if (x <= 1 && y <= 1) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x + i][y + i] == 'x') {
        cnt0++;
      } else if (v[x + i][y + i] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  if (x <= 1 && y >= 2) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x + i][y - i] == 'x') {
        cnt0++;
      } else if (v[x + i][y - i] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  return false;
}
int main() {
  vector<vector<char>> v(4, vector<char>(4));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (check(i, j, v)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}