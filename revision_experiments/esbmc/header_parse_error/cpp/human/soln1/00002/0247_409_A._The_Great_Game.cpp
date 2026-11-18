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
string a, b;
int wa, wb;
int main() {
  cin >> a >> b;
  for (int i = 0; i < a.size(); i += 2) {
    if (a[i] == '8' && b[i] == '[') wa++;
    if (a[i] == '[' && b[i] == '(') wa++;
    if (a[i] == '(' && b[i] == '8') wa++;
    if (b[i] == '8' && a[i] == '[') wb++;
    if (b[i] == '[' && a[i] == '(') wb++;
    if (b[i] == '(' && a[i] == '8') wb++;
  }
  if (wa > wb)
    puts("TEAM 1 WINS");
  else if (wa < wb)
    puts("TEAM 2 WINS");
  else
    puts("TIE");
  return 0;
}