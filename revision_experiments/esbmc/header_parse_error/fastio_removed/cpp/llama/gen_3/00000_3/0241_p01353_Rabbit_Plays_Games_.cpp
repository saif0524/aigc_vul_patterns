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

struct Character {
    int health, attack, defense, agility;
};

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    vector<Character> characters(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> characters[i].health >> characters[i].attack >> characters[i].defense >> characters[i].agility;
    }

    sort(begin(characters), end(characters), [](const Character& a, const Character& b) {
        return a.agility > b.agility;
    });

    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + characters[i].attack - characters[0].defense;
    }

    vector<long long> dp(1 << n);
    for (int mask = 1; mask < (1 << n); ++mask) {
        int last = __builtin_ctz(mask);
        int totalDamage = prefix[last];
        if (mask == (1 << last)) {
            dp[mask] = totalDamage;
            continue;
        }
        dp[mask] = LLONG_MAX;
        for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {
            int otherMask = mask ^ subMask;
            if (otherMask == 0) continue;
            dp[mask] = min(dp[mask], dp[subMask] + dp[otherMask] + totalDamage);
        }
        dp[mask] = min(dp[mask], dp[mask ^ (1 << last)] + totalDamage);
    }

    long long ans = dp.back();
    if (ans >= characters[0].health) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}