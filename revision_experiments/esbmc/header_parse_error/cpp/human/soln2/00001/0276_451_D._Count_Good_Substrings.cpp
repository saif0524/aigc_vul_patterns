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
const int maxn = 100005;
long long cntodd[2], cnteven[2];
char buf[maxn];
int main() {
  scanf("%s", buf + 1);
  int len = strlen(buf + 1);
  long long sumodd = 0, sumeven = 0;
  for (int i = 1; i <= len; i++) {
    int now = buf[i] - 'a';
    if (i & 1)
      cntodd[now]++;
    else
      cnteven[now]++;
    if (i & 1) {
      sumodd += cntodd[now];
      sumeven += cnteven[now];
    } else {
      sumodd += cnteven[now];
      sumeven += cntodd[now];
    }
  }
  cout << sumeven << " " << sumodd << endl;
  return 0;
}