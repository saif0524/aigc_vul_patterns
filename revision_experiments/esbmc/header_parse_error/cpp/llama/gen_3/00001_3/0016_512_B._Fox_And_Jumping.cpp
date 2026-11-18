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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<ll> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = costs[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        ll gcd = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) > 0) {
                if (gcd == 0) {
                    gcd = lengths[i];
                } else {
                    gcd = __gcd(gcd, lengths[i]);
                }
            }
        }

        if (gcd == 1) {
            for (int i = 0; i < n; i++) {
                if (dp[mask][i] > 0) {
                    cout << dp[mask][i] << endl;
                    return 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                ll new_cost = dp[mask][i] + costs[i];
                if (dp[mask | (1 << i)][i] == 0 || dp[mask | (1 << i)][i] > new_cost) {
                    dp[mask | (1 << i)][i] = new_cost;
                }
            }
        }
    }

    cout << -1 << endl;
}