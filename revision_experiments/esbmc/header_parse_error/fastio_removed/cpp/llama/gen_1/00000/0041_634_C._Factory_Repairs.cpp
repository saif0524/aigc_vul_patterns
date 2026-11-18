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

#define int long long

using namespace std;

const int maxn = 200005;

int n, k, a, b, q;
int orders[maxn];

void update(int day, int numOrders) {
    orders[day] += numOrders;
}

int calculateMaxFilledOrders(int repairStartDay) {
    int maxFilledOrders = 0;

    for (int day = 1; day <= n; day++) {
        if (day < repairStartDay) {
            maxFilledOrders += min(orders[day], b);
        } else if (day >= repairStartDay && day < repairStartDay + k) {
            // No production during repair
            continue;
        } else {
            maxFilledOrders += min(orders[day], a);
        }
    }

    return maxFilledOrders;
}

signed main() {
    ((void)0);
    ((void)0);

    cin >> n >> k >> a >> b >> q;

    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int day, numOrders;
            cin >> day >> numOrders;
            update(day, numOrders);
        } else {
            int repairStartDay;
            cin >> repairStartDay;
            cout << calculateMaxFilledOrders(repairStartDay) << '\n';
        }
    }

    return 0;
}