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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, v, t;
    cin >> x >> v >> t;

    int q;
    cin >> q;

    vector<tuple<char, int, int>> queries;
    for (int i = 0; i < q; ++i) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        queries.emplace_back(type, a, b);
    }

    for (auto& [type, a, b] : queries) {
        if (type == '?') {
            int pos = x + v * (t - a);
            if (pos <= b && pos >= a) {
                cout << "L " << pos << "\n";
            } else {
                cout << "N\n";
            }
        } else if (type == 'L') {
            x = a;
            v = b;
            t = 0;
        }
    }

    return 0;
}