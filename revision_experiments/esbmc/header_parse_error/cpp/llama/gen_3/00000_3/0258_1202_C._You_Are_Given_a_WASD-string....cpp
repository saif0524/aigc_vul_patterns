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

int calc(string s) {
    int minx = 0, maxx = 0, miny = 0, maxy = 0;
    int x = 0, y = 0;

    for (char c : s) {
        if (c == 'W') y++;
        if (c == 'S') y--;
        if (c == 'A') x--;
        if (c == 'D') x++;

        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    return (maxx - minx + 1) * (maxy - miny + 1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int ans = INT_MAX;
        ans = min(ans, calc(s + "W"));
        ans = min(ans, calc(s + "A"));
        ans = min(ans, calc(s + "S"));
        ans = min(ans, calc(s + "D"));

        for (int i = 0; i < s.size(); i++) {
            string temp = s;
            temp.insert(i, "W");
            ans = min(ans, calc(temp));
            temp = s;
            temp.insert(i, "A");
            ans = min(ans, calc(temp));
            temp = s;
            temp.insert(i, "S");
            ans = min(ans, calc(temp));
            temp = s;
            temp.insert(i, "D");
            ans = min(ans, calc(temp));
        }

        cout << ans << "\n";
    }

    return 0;
}