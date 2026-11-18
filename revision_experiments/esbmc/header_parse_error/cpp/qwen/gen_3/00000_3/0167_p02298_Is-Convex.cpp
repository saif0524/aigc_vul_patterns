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

int crossProduct(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    return (B.first - A.first) * (C.second - B.second) - (B.second - A.second) * (C.first - B.first);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &p : points) {
        cin >> p.first >> p.second;
    }
    int sign = 0;
    for (int i = 0; i < n; ++i) {
        int cp = crossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (cp != 0) {
            if (sign == 0) sign = cp > 0 ? 1 : -1;
            else if ((cp > 0 && sign == -1) || (cp < 0 && sign == 1)) {
                cout << "0";
                return 0;
            }
        }
    }
    cout << "1";
}