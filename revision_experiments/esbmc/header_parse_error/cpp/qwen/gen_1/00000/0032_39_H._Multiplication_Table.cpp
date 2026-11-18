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

string convert(int num, int base) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        result += to_string(num % base);
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int k;
    cin >> k;
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            cout << convert(i * j, k);
            if (j < k - 1) cout << "  ";
        }
        cout << endl;
    }
    return 0;
}