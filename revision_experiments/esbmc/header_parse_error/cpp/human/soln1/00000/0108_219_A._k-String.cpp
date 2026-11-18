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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ara[26];
  for (int i = 0; i < 26; i++) {
    ara[i] = 0;
  }
  for (int i = 0, len = s.length(); i < len; i++) {
    ara[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (ara[i] % n != 0) {
      printf("-1");
      return 0;
    }
    ara[i] /= n;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < ara[i]; j++) {
        printf("%c", i + 'a');
      }
    }
  }
  printf("\n");
}