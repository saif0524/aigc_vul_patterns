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

struct Parcel {
    int in, out, w, s, v;
};

bool operator<(const Parcel &a, const Parcel &b) {
    return a.out < b.out;
}

int main() {
    int n, S;
    cin >> n >> S;
    vector<Parcel> parcels(n);
    for (auto &p : parcels) cin >> p.in >> p.out >> p.w >> p.s >> p.v;
    sort(parcels.begin(), parcels.end());

    int dp[1001] = {0};
    set<pair<int, int>> platform; // {weight, index}

    for (int time = 0; time < 2*n; ++time) {
        while (!platform.empty() && begin(platform)->first > dp[time]) {
            dp[time] -= begin(platform)->first;
            platform.erase(begin(platform));
        }
        for (int i = 0; i < n; ++i) {
            if (parcels[i].in == time) {
                if (dp[time] + parcels[i].w <= S && (platform.empty() || (--end(platform))->second + parcels[i].w <= parcels[i].s)) {
                    dp[parcels[i].out] = max(dp[parcels[i].out], dp[time] + parcels[i].w);
                    platform.insert({parcels[i].w, parcels[i].s});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 2*n; ++i) ans = max(ans, dp[i]);
    cout << ans;
}