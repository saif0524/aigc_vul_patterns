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
int main(void) {
  int Count, Number;
  char E[5];
  scanf("%d", &Number);
  gets(E);
  char String[Number + 1];
  gets(String);
  for (Count = 0; Count < Number; Count++) {
    if (String[Count] != 'a' && String[Count] != 'e' && String[Count] != 'i' &&
        String[Count] != 'o' && String[Count] != 'u' && String[Count] != 'y')
      printf("%c", String[Count]);
    else {
      if (String[Count] != String[Count - 1]) printf("%c", String[Count]);
      if ((String[Count] == 'e' || String[Count] == 'o') &&
          String[Count - 1] == String[Count] &&
          String[Count - 2] != String[Count] &&
          String[Count + 1] != String[Count])
        printf("%c", String[Count]);
    }
  }
  printf("\n");
  return 0;
}