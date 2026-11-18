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

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    ll total_damage = 0;
    ll played_cards = 0;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<pair<int, int>> cards(k);

        for (int j = 0; j < k; j++) {
            int c, d;
            cin >> c >> d;
            cards[j] = make_pair(c, d);
        }

        sort(cards.begin(), cards.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<ll> dp(4, 0);
        for (int j = k - 1; j >= 0; j--) {
            vector<ll> new_dp(4, 0);
            for (int cost = 0; cost < 4; cost++) {
                new_dp[cost] = max(dp[cost], dp[min(3, cost + cards[j].first)] + cards[j].second);
            }
            dp = new_dp;
        }

        total_damage += dp[3];

        int turn_played = 0;
        for (int j = k - 1; j >= 0; j--) {
            if (turn_played + cards[j].first <= 3 && dp[3] == dp[min(3, turn_played + cards[j].first)] + cards[j].second) {
                turn_played += cards[j].first;
                played_cards++;
            }
        }

        if (played_cards % 10 == 0 && i < n - 1) {
            int last_played = -1;
            for (int j = k - 1; j >= 0; j--) {
                if (turn_played + cards[j].first <= 3 && dp[3] == dp[min(3, turn_played + cards[j].first)] + cards[j].second) {
                    last_played = j;
                }
            }
            if (last_played != -1) {
                total_damage += cards[last_played].second;
            }
        }
    }

    cout << total_damage << endl;

    return 0;
}