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
int main() {
  int score[5], wrong_answer[5], hacks = 0, right, wrong,
                                 highest[5] = {2, 4, 6, 8, 10},
                                 ini[5] = {150, 300, 450, 600, 750}, sum = 0, i;
  for (i = 0; i < 5; i++) scanf("%d", &score[i]);
  for (i = 0; i < 5; i++) scanf("%d", &wrong_answer[i]);
  scanf("%d %d", &right, &wrong);
  hacks = right * 100 + (wrong * (-50));
  for (i = 0; i < 5; i++) {
    sum = sum +
          (ini[i] > ((250 - score[i]) * (highest[i]) - (50 * wrong_answer[i]))
               ? ini[i]
               : ((250 - score[i]) * (highest[i]) - (50 * wrong_answer[i])));
  }
  printf("%d\n", sum + hacks);
  return 0;
}