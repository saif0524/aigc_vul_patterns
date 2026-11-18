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
int n, v[100];
string s[100], c;
int def() {
  string s1, s2, s3;
  cin >> s1 >> s2;
  int p = s1.rfind("&") + 1, q = s1.find("*"), v1;
  if (q < 0) {
    v1 = 0 - p;
    q = 1000;
  } else
    v1 = (s1.size() - q) - p;
  s3 = s1.substr(p, q - p);
  if (s3 == "void") {
    for (int i = n + 1; i < 100; i++)
      if (s[i] == s2) {
        v[i] = v1;
        return 0;
      }
    s[n] = s2;
    v[n] = v1;
    return 0;
  } else if (s3 == "errtype") {
    for (int i = n + 1; i < 100; i++)
      if (s[i] == s2) {
        v[i] = -1;
        return 0;
      }
    s[n] = s2;
    v[n] = -1;
    return 0;
  }
  bool b = true;
  for (int j = n + 1; j < 100; j++)
    if (s[j] == s3) {
      if (v[j] < 0)
        v1 = -1;
      else
        v1 += v[j];
      b = false;
    }
  if (b) v1 = -1;
  for (int i = n + 1; i < 100; i++)
    if (s[i] == s2) {
      v[i] = v1;
      return 0;
    }
  s[n] = s2;
  v[n] = v1;
  return 0;
}
int of() {
  string s1, s2;
  cin >> s1;
  int p = s1.rfind("&") + 1, q = s1.find("*"), v1;
  if (q < 0) {
    v1 = 0 - p;
    q = 1000;
  } else
    v1 = (s1.size() - q) - p;
  s2 = s1.substr(p, q - p);
  if (s2 == "void") {
    cout << "void";
    while (v1--) cout << "*";
    cout << endl;
    return 0;
  }
  if (s2 == "errtype") {
    cout << "errtype" << endl;
    return 0;
  }
  bool b = true;
  for (int i = n + 1; i < 100; i++)
    if (s[i] == s2) {
      if (v[i] < 0)
        v1 = -1;
      else
        v1 += v[i];
      if (v1 < 0)
        cout << "errtype" << endl;
      else {
        cout << "void";
        while (v1--) cout << "*";
        cout << endl;
      }
      b = false;
    }
  if (b) cout << "errtype" << endl;
  return 0;
}
int main() {
  cin >> n;
  while (n--) {
    cin >> c;
    if (c == "typedef")
      def();
    else
      of();
  }
  return 0;
}