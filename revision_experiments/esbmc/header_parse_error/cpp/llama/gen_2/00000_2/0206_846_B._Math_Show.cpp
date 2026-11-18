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

typedef long long ll;

const int N = 50;

ll dp[N][N * N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    ll M;
    cin >> n >> k >> M;

    vector<ll> t(k);
    for (int i = 0; i < k; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    vector<ll> s(k + 1);
    for (int i = 0; i < k; i++) {
        s[i + 1] = s[i] + t[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * k; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n * k; j++) {
            if (dp[i][j] == -1) continue;

            for (int l = 0; l <= k; l++) {
                if (j + l > n * k) continue;
                if (s[l] > M) continue;

                dp[i + 1][j + l] = max(dp[i + 1][j + l], dp[i][j] + l + (l == k ? 1 : 0));
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * k; j++) {
            if (dp[i][j] != -1 && s[j] <= M) {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans;

    return 0;
}