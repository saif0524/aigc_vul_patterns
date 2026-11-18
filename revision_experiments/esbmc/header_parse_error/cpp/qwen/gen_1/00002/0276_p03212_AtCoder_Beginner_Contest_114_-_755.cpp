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

bool isShichiGoSan(int n) {
    bool has3 = false, has5 = false, has7 = false;
    while (n > 0) {
        int d = n % 10;
        if (d == 3) has3 = true;
        else if (d == 5) has5 = true;
        else if (d == 7) has7 = true;
        else return false;
        n /= 10;
    }
    return has3 && has5 && has7;
}

int countShichiGoSan(int N) {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (isShichiGoSan(i)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countShichiGoSan(N) << endl;
    return 0;
}