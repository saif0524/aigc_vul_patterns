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
char str[100010], h[100010], m[100010];
long long int mh, mm, lh, lm;
long long int priority(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  return ((c - 'A') + 10);
}
void find_time(long long int r) {
  long long int i, p = 1;
  for (i = (lh - 1); i >= 0; i--) {
    mh += p * priority(h[i]);
    p *= r;
  }
  p = 1;
  for (i = (lm - 1); i >= 0; i--) {
    mm += p * priority(m[i]);
    p *= r;
  }
}
int main() {
  ((void)0);
  ((void)0);
  scanf("%s", str);
  long long int i, j, mymax;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ':') {
      h[i] = '\0';
      break;
    }
    h[i] = str[i];
  }
  j = 0;
  i++;
  for (;; i++) {
    if (str[i] == '\0') {
      m[j] = '\0';
      break;
    } else
      m[j++] = str[i];
  }
  lh = strlen(h);
  lm = strlen(m);
  bool um = 0, uh = 0, all = 1;
  for (i = (lh - 1); i >= 0; i--) {
    if (i < (lh - 1) && h[i] != '0') uh = 1;
    if (h[i] != '0') all = 0;
  }
  for (i = (lm - 1); i >= 0; i--) {
    if (i < (lm - 1) && m[i] != '0') um = 1;
    if (m[i] != '0') all = 0;
  }
  if (all) {
    cout << -1 << endl;
  } else if (uh == 0 && um == 0) {
    mh = 0;
    mm = 0;
    find_time(1);
    if (mh <= 23 & mm < 60) {
      cout << -1 << endl;
    } else if (mh == 24 && mm == 0) {
      cout << -1 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    mymax = 0;
    vector<long long int> r;
    for (i = 0; i < lh; i++) {
      mymax = max(mymax, priority(h[i]));
    }
    for (i = 0; i < lm; i++) {
      mymax = max(mymax, priority(m[i]));
    }
    for (i = mymax + 1;; i++) {
      mh = 0;
      mm = 0;
      find_time(i);
      if (mh <= 23 && mm < 60)
        r.push_back(i);
      else
        break;
    }
    if (r.size() != 0) {
      for (i = 0; i < r.size(); i++) cout << r[i] << " ";
      cout << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}