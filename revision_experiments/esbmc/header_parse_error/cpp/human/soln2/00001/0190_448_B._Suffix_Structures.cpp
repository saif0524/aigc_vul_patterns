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
int cnt[30];
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  bool atm = false;
  for (int i = 0, j = 0; i < n; ++i) {
    if (j < m && s[i] == t[j]) ++j;
    if (j == m) atm = true;
  }
  for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
  for (int i = 0; i < m; ++i) cnt[t[i] - 'a']--;
  bool arr = true;
  bool nt = true;
  for (int i = 0; i < 26; ++i) {
    arr &= cnt[i] == 0;
    nt &= cnt[i] >= 0;
  }
  if (atm)
    cout << "automaton" << endl;
  else if (arr)
    cout << "array" << endl;
  else if (nt)
    cout << "both" << endl;
  else
    cout << "need tree" << endl;
}