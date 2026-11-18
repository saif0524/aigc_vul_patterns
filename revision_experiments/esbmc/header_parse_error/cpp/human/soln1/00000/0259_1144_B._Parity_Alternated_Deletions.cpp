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
int n;
vector<int> myodd, myeven;
bool cmp(int a, int b) { return a > b; }
int main() {
  scanf("%d", &n);
  int tmp;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    sum += tmp;
    if (tmp % 2 == 0) {
      myeven.push_back(tmp);
    } else {
      myodd.push_back(tmp);
    }
  }
  sort(myeven.begin(), myeven.end(), cmp);
  sort(myodd.begin(), myodd.end(), cmp);
  int ans1 = 0;
  int len1 = myeven.size(), len2 = myodd.size();
  int i = 0, j = 0;
  for (; i < len1 && j < len2; ++i, ++j) {
    ans1 += myeven[i];
    ans1 += myodd[j];
  }
  if (i < len1) {
    ans1 += myeven[i];
  }
  if (j < len2) {
    ans1 += myodd[j];
  }
  int ans2 = 0;
  i = 0;
  j = 0;
  for (; i < len1 && j < len2; ++i, ++j) {
    ans2 += myodd[j];
    ans2 += myeven[i];
  }
  if (j < len2) {
    ans2 += myodd[j];
  }
  if (i < len1) {
    ans2 += myeven[i];
  }
  printf("%d\n", sum - max(ans1, ans2));
  return 0;
}