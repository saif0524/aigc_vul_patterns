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
string s[505];
vector<int> P, N;
int main() {
  int id = 0, pos = 0, neg = 0;
  while (cin >> s[id]) {
    if (s[id] == "=") break;
    if (s[id] == "?") {
      if (id == 0 || s[id - 1] == "+")
        pos++;
      else
        neg++;
    }
    id++;
    cin >> s[id];
    if (s[id] == "=") break;
    id++;
  }
  int n;
  cin >> n;
  int dif = pos - neg;
  for (int i = 0; i < pos; i++) P.push_back(1);
  for (int i = 0; i < neg; i++) N.push_back(1);
  if (dif < n) {
    int i = 0;
    while (dif < n && i < pos) {
      if (dif + n - 1 < n) {
        dif += n - 1;
        P[i++] = n;
      } else {
        P[i++] = 1 + n - dif;
        dif = n;
      }
    }
    if (dif != n) {
      cout << "Impossible" << endl;
      return 0;
    }
  } else if (dif > n) {
    int i = 0;
    while (dif > n && i < neg) {
      if (dif - n + 1 > n) {
        dif -= n - 1;
        N[i++] = n;
      } else {
        N[i++] = 1 + dif - n;
        dif = n;
      }
    }
    if (dif != n) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  for (int i = 0, j = 0, k = 0; i <= id; i++) {
    if (s[i] == "?") {
      if (i == 0 || s[i - 1] == "+")
        cout << P[j++];
      else
        cout << N[k++];
    } else
      cout << " " << s[i];
  }
  cout << " " << n << endl;
  return 0;
}