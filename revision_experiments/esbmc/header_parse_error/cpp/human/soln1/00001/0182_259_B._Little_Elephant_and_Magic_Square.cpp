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
int cell[4][4];
void go() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << cell[i][j] << " ";
    cout << endl;
  }
}
int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cin >> cell[i][j];
  }
  cell[0][0] = (cell[1][2] + cell[2][1]) / 2;
  cell[2][2] = (cell[0][1] + cell[1][0]) / 2;
  cell[1][1] = ((cell[0][0] + cell[0][2]) - cell[2][1]);
  go();
  return 0;
}