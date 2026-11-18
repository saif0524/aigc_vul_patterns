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
using ll = long long;
using ld = long double;
using ull = unsigned long long;

const bool typetest = 1;
const int N = 1e5 + 5;
int n, a[N];
int k;
string s;
string dp[N];

void Read()
{
    cin >> n >> k >> s;
}

char Max(char c)
{
    return (c == 'a' || c == 'a' + k - 1) ? 'a' : char(c - 1);
}

void Solve()
{
    for (int i = 0; i < n; ++i)
        dp[i] = char('z' + 1);
    dp[0] = Max(s[0]);
    if (n > 1)
    {
        string v = "";
        v.push_back(Max(s[1]));
        v.push_back(s[0]);
        dp[1] = min(dp[1], v);
        v.clear();
        v.push_back(Max(s[0]));
        v.push_back(Max(s[1]));
    }
    //cout << dp[0] << " " << dp[1] << '\n';
    for (int i = 0; i < n; ++i)
    {
        // /cout << i << ": " << dp[i] << "\n";
        if (i + 1 < n)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + Max(s[i + 1]));
            dp[i + 1] = min(dp[i + 1], dp[i].substr(0, dp[i].size() - 1) + s[i + 1] + dp[i].back());
        }
        if (i + 2 < n)
        {
            dp[i + 2] = min(dp[i + 2], dp[i] + Max(s[i + 2]) + s[i + 1]);
            dp[i + 2] = min(dp[i + 2], dp[i].substr(0, dp[i].size() - 1) + s[i + 2] + dp[i].back() + s[i + 1]);
        }
    }
    cout << dp[n - 1] << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t(1);
    if (typetest)
        cin >> t;
    for (int _ = 1; _ <= t; ++_)
    {
        Read();
        Solve();
    }
}