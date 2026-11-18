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
const int mod = 1e9 + 7;
struct node {
  int id;
  int c;
} s[300050];
bool cmp(node a, node b) { return a.c < b.c; }
int main() {
  int n, x1, x2;
  scanf("%d%d%d", &n, &x1, &x2);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i].c);
    s[i].id = i;
  }
  sort(s + 1, s + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    int tmp = x1 / s[n - i + 1].c;
    if (x1 % s[n - i + 1].c) tmp++;
    int res = i - tmp;
    if (res > 0 && (x2 + res - 1) / res <= s[n - res + 1].c) {
      cout << "Yes" << endl;
      cout << tmp << " " << res << endl;
      for (int j = n - i + 1; j < n - res + 1; j++) cout << s[j].id << " ";
      cout << endl;
      for (int j = n - res + 1; j <= n; j++) cout << s[j].id << " ";
      cout << endl;
      exit(0);
    }
    tmp = x2 / s[n - i + 1].c;
    if (x2 % s[n - i + 1].c) tmp++;
    res = i - tmp;
    if (res > 0 && (x1 + res - 1) / res <= s[n - res + 1].c) {
      cout << "Yes" << endl;
      cout << res << " " << tmp << endl;
      for (int j = n - res + 1; j <= n; j++) cout << s[j].id << " ";
      cout << endl;
      for (int j = n - i + 1; j <= n - res; j++) cout << s[j].id << " ";
      cout << endl;
      exit(0);
    }
  }
  cout << "No";
  return 0;
}