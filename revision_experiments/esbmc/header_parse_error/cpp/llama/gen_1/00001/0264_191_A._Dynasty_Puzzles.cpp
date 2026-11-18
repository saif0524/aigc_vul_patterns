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

int dp[100005][27][27];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    memset(dp, -1, sizeof(dp));

    for (int first = 0; first < n; first++) {
        for (int last = 0; last < n; last++) {
            for (int first_letter = 0; first_letter < 26; first_letter++) {
                for (int last_letter = 0; last_letter < 26; last_letter++) {
                    if (names[first][0] - 'a' == first_letter && names[last][names[last].size() - 1] - 'a' == last_letter) {
                        int current_length = names[first].size();
                        if (first == last) {
                            dp[first][first_letter][last_letter] = current_length;
                        } else {
                            for (int k = first + 1; k < last; k++) {
                                if (names[k][0] - 'a' == last_letter && dp[first][first_letter][names[k][names[k].size() - 1] - 'a'] != -1) {
                                    dp[first][first_letter][last_letter] = max(dp[first][first_letter][last_letter], dp[first][first_letter][names[k][names[k].size() - 1] - 'a'] + names[last].size());
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int first = 0; first < n; first++) {
        ans = max(ans, dp[first][names[first][0] - 'a'][names[first][names[first].size() - 1] - 'a']);
    }

    cout << ans << endl;

    return 0;
}