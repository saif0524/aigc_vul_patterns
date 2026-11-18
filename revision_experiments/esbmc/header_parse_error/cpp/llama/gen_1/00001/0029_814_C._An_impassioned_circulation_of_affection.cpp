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

int n, m, q, ans;
string s, c;
int a[1505], f[27];

void init(int len) {
    int cnt = 0;
    for (int i = 1; i <= len; i++) {
        if (s[i - 1] == c[0]) {
            a[++cnt] = i;
        }
    }
    a[++cnt] = n + 1;
}

int main() {
    cin >> n >> s >> q;
    while (q--) {
        ans = 0;
        int len;
        cin >> len >> c;
        init(n);
        for (int i = 1; i <= 26; i++) f[i] = 0;
        for (int i = 1; i < n + 1; i++) f[s[i - 1] - 'a' + 1]++;
        for (int i = 1; a[i] <= n; i++) {
            int tot = 0;
            for (int j = 1; j <= 26; j++) {
                if (j != c[0] - 'a' + 1) {
                    tot += min(f[j], len);
                }
            }
            int cnt = 0, l = 1, r = i, mid, slen;
            while (l <= r) {
                mid = (l + r) / 2;
                slen = a[i] - a[mid] + 1 - (i - mid);
                if (tot + slen <= len) {
                    cnt = max(cnt, i - mid + 1);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, cnt);
            memset(f, 0, sizeof f);
            for (int j = 1; j < n + 1; j++) f[s[j - 1] - 'a' + 1]++;
        }
        cout << ans << endl;
    }
    return 0;
}