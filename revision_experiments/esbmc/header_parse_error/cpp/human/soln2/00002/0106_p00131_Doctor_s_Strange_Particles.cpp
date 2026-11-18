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
using ll = long long;
using pii = pair<int, int>;

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

void solve() {
  int a[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> a[i][j];
    }
  }
  int tmp[10][10];
  for (int i = 0; i < 1 << 10; i++) {
    memset(tmp, 0, sizeof(tmp));
    for (int j = 0; j < 10; j++) {
      if (i >> j & 1) tmp[0][j] = 1;
    }
    for (int j = 0; j + 1 < 10; j++) {
      for (int k = 0; k < 10; k++) {
        int sum = tmp[j][k];
        for (int l = 0; l < 4; l++) {
          int ny = j + dy[l], nx = k + dx[l];
          if (ny >= 0 && ny < 10 && nx >= 0 && nx < 10) sum += tmp[ny][nx];
        }
        if ((sum + a[j][k]) % 2 == 0) continue;
        tmp[j + 1][k] = 1;
      }
    }
    int tmp2[10][10];
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        tmp2[j][k] = tmp[j][k];
        for (int l = 0; l < 4; l++) {
          int ny = j + dy[l], nx = k + dx[l];
          if (ny >= 0 && ny < 10 && nx >= 0 && nx < 10) (tmp2[j][k] += tmp[ny][nx]) %= 2;
        }
      }
    }
    bool ng = false;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        ng |= tmp2[j][k] != a[j][k];
      }
    }
    if (ng) continue;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        cout << tmp[j][k] << " \n"[k + 1 == 10];
      }
    }
    return;
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }

  return 0;
}