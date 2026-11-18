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
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    int n = s.size();
    string ans(n, '?');
    int l = 0, r = n - 1;
    int i = 0, j = 0, k = n - 1;

    for (int turn = 0; turn < n; turn++) {
        if (turn % 2 == 0) {
            if (s[i] < t[k]) {
                ans[l++] = s[i++];
            } else {
                ans[r--] = s[j--];
            }
        } else {
            if (t[k] > s[j]) {
                ans[l++] = t[k--];
            } else {
                ans[r--] = t[i++];
            }
        }
    }

    cout << ans << endl;

    return 0;
}