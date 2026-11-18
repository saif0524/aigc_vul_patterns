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
const int mod = 998244353;

int n, k;
int a[100005], cnt[100005], dp[100005];

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j >= 1; j--) {
            if (++cnt[a[j]] == 2) {
                cur++;
            }
            if (cur > k) {
                break;
            }
            dp[i] = (dp[i] + dp[j - 1]) % mod;
        }
    }

    cout << dp[n] << '\n';
    return 0;
}