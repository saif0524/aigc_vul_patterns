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

const int MAX_N = 105;

int n, m;
bitset<MAX_N> bulbs;
bitset<MAX_N> buttons[MAX_N];

void pressButton(int i) {
    bulbs |= buttons[i];
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int bulb;
            cin >> bulb;
            buttons[i].set(bulb);
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        bulbs.reset();

        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) != 0) {
                pressButton(i);
            }
        }

        if (bulbs.count() == m) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}