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
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    map<int, int> cnt;
    for (int x : a) cnt[x]++;

    int mx_cnt = 0, mx_num;
    for (auto& [x, c] : cnt) {
        if (c > mx_cnt) {
            mx_cnt = c;
            mx_num = x;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == mx_num) continue;

        map<int, int> pre;
        pre[0] = -1;

        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (a[j] == mx_num) ? 1 : (a[j] == i) ? -1 : 0;

            if (pre.count(sum)) {
                ans = max(ans, j - pre[sum]);
            } else {
                pre[sum] = j;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}