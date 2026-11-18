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
    long long a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    long long xMove = (abs(x1 - x2) + abs(y1 - y2)) / 2;
    long long yMove = xMove;

    if (abs(x1 + y1) % (2 * a) <= abs(x1 - y1) % (2 * b)) {
        if ((x1 + y1) % (2 * a) < 0) {
            xMove = (abs(x1 + y1) + (2 * a) - 1) / (2 * a);
        } else {
            xMove = (abs(x1 + y1)) / (2 * a);
        }
        if ((x2 + y2) % (2 * a) < 0) {
            xMove = max(xMove, (abs(x2 + y2) + (2 * a) - 1) / (2 * a));
        } else {
            xMove = max(xMove, (abs(x2 + y2)) / (2 * a));
        }
    } else {
        if ((x1 - y1) % (2 * b) < 0) {
            yMove = (abs(x1 - y1) + (2 * b) - 1) / (2 * b);
        } else {
            yMove = (abs(x1 - y1)) / (2 * b);
        }
        if ((x2 - y2) % (2 * b) < 0) {
            yMove = max(yMove, (abs(x2 - y2) + (2 * b) - 1) / (2 * b));
        } else {
            yMove = max(yMove, (abs(x2 - y2)) / (2 * b));
        }
    }
    cout << min(xMove, yMove) << endl;
    return 0;
}