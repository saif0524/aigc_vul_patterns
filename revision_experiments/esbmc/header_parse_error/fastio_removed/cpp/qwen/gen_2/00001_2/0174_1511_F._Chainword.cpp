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

const int MOD = 998244353;
const int MAX_N = 8;
const int MAX_M = 1005;

int n, m;
vector<string> words;
vector<int> lengths;
int memo1[MAX_M][1<<MAX_N];
int memo2[MAX_M][1<<MAX_N];

int count_ways(int pos, int mask, vector<int>& memo) {
    if (pos == m) return 1;
    if (memo[pos][mask] != -1) return memo[pos][mask];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i)) && pos + lengths[i] <= m) {
            ans = (ans + count_ways(pos + lengths[i], mask | (1 << i), memo)) % MOD;
        }
    }
    memo[pos][mask] = ans;
    return ans;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> m;
    words.resize(n);
    lengths.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        lengths[i] = words[i].size();
    }
    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));
    long long ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int ways1 = count_ways(0, i, memo1);
        int ways2 = count_ways(0, i, memo2);
        ans = (ans + 1LL * ways1 * ways2) % MOD;
    }
    cout << ans << "\n";
    return 0;
}