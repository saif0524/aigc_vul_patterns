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

int n, m, k, q;
set<int> rows[100005];
set<int> cols[100005];

struct Rectangle {
    int x1, y1, x2, y2;
};

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        rows[x].insert(y);
        cols[y].insert(x);
    }

    for (int i = 0; i < q; i++) {
        Rectangle rect;
        cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
        bool isProtected = true;
        for (int x = rect.x1; x <= rect.x2; x++) {
            for (int y = rect.y1; y <= rect.y2; y++) {
                if (rows[x].lower_bound(y) == rows[x].end() || *rows[x].lower_bound(y) != y) {
                    if (cols[y].lower_bound(x) == cols[y].end() || *cols[y].lower_bound(x) != x) {
                        bool isCovered = false;
                        auto it = rows[x].lower_bound(y);
                        if (it != rows[x].begin()) {
                            it--;
                            if (*it < rect.y1) {
                                isCovered = true;
                            }
                        }
                        it = rows[x].upper_bound(y);
                        if (it != rows[x].end() && *it > rect.y2) {
                            isCovered = true;
                        }

                        if (!isCovered) {
                            it = cols[y].lower_bound(x);
                            if (it != cols[y].begin()) {
                                it--;
                                if (*it < rect.x1) {
                                    isCovered = true;
                                }
                            }
                            it = cols[y].upper_bound(x);
                            if (it != cols[y].end() && *it > rect.x2) {
                                isCovered = true;
                            }
                        }

                        if (!isCovered) {
                            isProtected = false;
                            break;
                        }
                    }
                }
            }
            if (!isProtected) {
                break;
            }
        }

        if (isProtected) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}