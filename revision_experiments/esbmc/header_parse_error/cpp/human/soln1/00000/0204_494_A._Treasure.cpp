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
  int t = 0, sl = 0;
  char s[100010];
  cin >> s;
  for (int i = 0; i < strlen(s); i++)
    if (s[i] == '#') {
      t++;
    } else if (s[i] == '(')
      sl++;
    else
      sl--;
  if (sl <= 0)
    cout << "-1";
  else {
    int t1 = 0, t2 = 0;
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == '#') {
        t1++;
        if (t1 != t) {
          t2--;
        } else
          t2 = t2 - sl + t - 1;
      } else if (s[i] == '(')
        t2++;
      else
        t2--;
      if (t2 < 0) {
        cout << "-1";
        return 0;
      }
    }
    for (int i = 1; i < t; i++) cout << '1' << endl;
    cout << sl - t + 1;
  }
}