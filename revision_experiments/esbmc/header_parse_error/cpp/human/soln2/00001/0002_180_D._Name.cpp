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
int c1[26];
int c2[26][5009];
int main() {
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    c1[s[i] - 'a']++;
  }
  for (int i = 1; i <= t.length(); i++) {
    c2[t[i - 1] - 'a'][i]++;
    for (int j = 0; j < 26; j++) {
      c2[j][i + 1] = c2[j][i];
    }
  }
  for (int i = t.length() + 1; i <= 5000; i++) {
    for (int j = 0; j < 26; j++) {
      c2[j][i + 1] = c2[j][i];
    }
  }
  if (s.length() > t.length()) {
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      if (c1[i] < c2[i][t.length()]) {
        ok = false;
      }
    }
    if (ok) {
      cout << t;
      for (int i = 0; i < 26; i++) {
        while (c1[i] > c2[i][t.length()]) {
          cout << char(i + 'a');
          c1[i]--;
        }
      }
      return 0;
    }
  }
  for (int pos = s.length() - 1; pos >= 0; pos--) {
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      if (c1[i] < c2[i][pos]) {
        ok = false;
      }
    }
    if (!ok) continue;
    for (int i = 0; i < 26; i++) {
      c1[i] -= c2[i][pos];
    }
    int j = t[pos] - 'a' + 1;
    while (j < 26 && !c1[j]) j++;
    if (j == 26) {
      for (int i = 0; i < 26; i++) {
        c1[i] += c2[i][pos];
      }
      continue;
    }
    c1[j]--;
    for (int k = 0; k < pos; k++) {
      cout << t[k];
    }
    cout << char(j + 'a');
    for (int i = 0; i < 26; i++) {
      while (c1[i]) {
        cout << char(i + 'a');
        c1[i]--;
      }
    }
    return 0;
  }
  cout << -1 << endl;
}