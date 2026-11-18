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

bool isGreater(string a, string b) {
    if (a.length() < b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return false;
    }
    else if (a.length() > b.length()) {
        return true;
    }
    else {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return false;
    }
}

string nextGreater(string s, string t) {
    sort(s.begin(), s.end());
    do {
        if (isGreater(s, t)) {
            return s;
        }
    } while (next_permutation(s.begin(), s.end()));
    return "-1";
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << nextGreater(s, t) << endl;
    return 0;
}