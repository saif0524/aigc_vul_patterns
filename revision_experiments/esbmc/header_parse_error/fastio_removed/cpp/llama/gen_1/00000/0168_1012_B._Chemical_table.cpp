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

int n, m, q;
set<int> x, y;
bool used[200005][2];

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        x.insert(r);
        y.insert(c);
        used[r][0] = true;
        used[c][1] = true;
    }

    for (auto it = x.begin(); it != x.end(); ++it) {
        if (!used[*it][0]) x.erase(it);
    }

    for (auto it = y.begin(); it != y.end(); ++it) {
        if (!used[*it][1]) y.erase(it);
    }

    if (x.size() == n || y.size() == m) {
        cout << "0\n";
    } else if (x.size() == 0 || y.size() == 0) {
        cout << n + m - 1 << "\n";
    } else {
        cout << "1\n";
    }

    return 0;
}