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

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string smallest = s;
    if (k >= 1) {
        string t = s;
        reverse(t.begin(), t.end());
        string u = s + t;
        for (int i = 0; i <= n; ++i) {
            string temp = u.substr(i, n);
            smallest = min(smallest, temp);
        }
    }
    if (k >= 2) {
        string t = smallest;
        reverse(t.begin(), t.end());
        string u = smallest + t;
        for (int i = 0; i <= n; ++i) {
            string temp = u.substr(i, n);
            smallest = min(smallest, temp);
        }
    }

    cout << smallest << endl;

    return 0;
}