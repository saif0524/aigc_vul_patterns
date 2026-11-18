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
bool b;
long long ans, cnt, sum2;
string num_to_string(int num) {
  stringstream ss;
  ss << num;
  return ss.str();
}
void O_o() {
  ((void)0);
  ((void)0);
  ((void)0), ((void)0);
}
int main() {
  O_o();
  int n, k;
  string s;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s;
    set<int> ss;
    b = 0;
    for (int j = 0; j < ((int)(s.size())); j++) ss.insert(s[j] - '0');
    int x = 0;
    for (auto j : ss) {
      if (j != x) b = 1;
      if (x == k) break;
      x++;
    }
    if (((int)(ss.size())) < k + 1 || x != k) b = 1;
    if (!b) cnt++;
  }
  cout << cnt << endl;
  return 0;
}