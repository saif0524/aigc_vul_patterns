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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, T;
    cin >> n >> a >> b >> T;

    string s;
    cin >> s;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        int t = 1 + (s[i] == 'w' ? b : 0);
        int j = (i + 1) % n;
        int cnt = 1;
        while (t + a + 1 + (s[j] == 'w' ? b : 0) <= T) {
            t += a + 1 + (s[j] == 'w' ? b : 0);
            ++cnt;
            j = (j + 1) % n;
        }
        res = max(res, cnt);
    }

    for (int i = 1; i < n; ++i) {
        int t = 1 + (s[0] == 'w' ? b : 0) + a * i;
        int j = (i - 1 + n) % n;
        int cnt = 1;
        while (t + a + 1 + (s[j] == 'w' ? b : 0) <= T) {
            t += a + 1 + (s[j] == 'w' ? b : 0);
            ++cnt;
            j = (j - 1 + n) % n;
        }
        res = max(res, cnt);
    }

    cout << res << '\n';

    return 0;
}