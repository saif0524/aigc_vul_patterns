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

const long long INF = 1e18;
const int MAXN = 5005;

long long dp[MAXN][MAXN];
int tag[MAXN], s[MAXN];

int main() {
    ((void)0);
    ((void)0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> tag[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        memset(dp, 0, sizeof(dp));
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && tag[i] != tag[j]) {
                    long long diff = abs(s[i] - s[j]);
                    dp[i][j] = diff;
                    for (int k = 1; k <= n; k++) {
                        if (k != i && k != j && tag[k] != tag[i] && abs(2 << (k - 1) - 2 << (i - 1)) > abs(2 << (j - 1) - 2 << (i - 1))) {
                            dp[i][j] = max(dp[i][j], dp[k][i] + diff);
                        }
                        if (k != i && k != j && tag[k] != tag[j] && abs(2 << (k - 1) - 2 << (j - 1)) > abs(2 << (i - 1) - 2 << (j - 1))) {
                            dp[i][j] = max(dp[i][j], dp[k][j] + diff);
                        }
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}