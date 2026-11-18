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

int getWeight(char c) {
    return c - 'a' + 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<bool> used(n, false);
    int ans = -1;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 1; j--) {
            if (dp[i][j - 1] != -1) {
                int prevWeight = (i > 0 && used[i - 1]) ? getWeight(s[i - 1]) : 0;
                if (getWeight(s[i]) - prevWeight >= 2) {
                    int newWeight = dp[i][j - 1] + getWeight(s[i]);
                    if (dp[i + 1][j] == -1 || newWeight < dp[i + 1][j]) {
                        dp[i + 1][j] = newWeight;
                        used[i] = true;
                    }
                }
            }
        }
        if (dp[i + 1][k] != -1 && (ans == -1 || dp[i + 1][k] < ans)) {
            ans = dp[i + 1][k];
        }
    }

    cout << ans << endl;

    return 0;
}