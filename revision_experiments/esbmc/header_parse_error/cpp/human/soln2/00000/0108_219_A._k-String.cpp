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
int k;
int mp[30];
string s;
int main() {
  cin >> k >> s;
  if (s.size() % k != 0) puts("-1"), exit(0);
  for (int i = 0; i < s.size(); i++) mp[s[i] - 'a']++;
  for (int i = 0; i < s.size(); i++) {
    if (mp[s[i] - 'a'] % k == 0) continue;
    puts("-1");
    exit(0);
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    int n = mp[i] / k;
    for (int j = 0; j < n; j++) {
      ans += 'a' + i;
    }
  }
  for (int i = 0; i < k; i++) cout << ans;
  cout << endl;
}