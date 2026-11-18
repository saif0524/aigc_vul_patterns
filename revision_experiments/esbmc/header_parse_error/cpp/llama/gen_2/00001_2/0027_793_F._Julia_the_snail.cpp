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
    int n, m;
    cin >> n >> m;

    vector<int> h(n + 1);
    vector<int> hull(n + 1);

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        h[start] = max(h[start], end);
    }

    for (int i = 1; i <= n; i++) {
        hull[i] = max(hull[i], h[i]);

        for (int j = i - 1; j >= 1; j--) {
            if (hull[j] < hull[j + 1]) {
                hull[j] = hull[j + 1];
            } else {
                break;
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;
        int res = 0;

        for (int i = x; i <= y; i++) {
            if (h[i] > 0 && h[i] <= y) {
                res = max(res, h[i]);
            }

            int pos = upper_bound(hull.begin() + 1, hull.begin() + n + 1, y) - hull.begin() - 1;
            if (i < pos && hull[pos] > 0 && hull[pos] <= y) {
                res = max(res, hull[pos]);
            }
        }

        cout << res << endl;
    }

    return 0;
}