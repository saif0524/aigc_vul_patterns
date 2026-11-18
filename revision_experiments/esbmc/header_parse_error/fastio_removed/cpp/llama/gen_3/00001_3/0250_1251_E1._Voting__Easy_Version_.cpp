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

const int MAXN = 5005;

int t, n;
pair<int, int> mp[MAXN];

int main() {
    ((void)0);
    ((void)0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> mp[i].first >> mp[i].second;
        }
        sort(mp, mp + n);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            pq.push(mp[i].second);
            while (!pq.empty() && cnt < mp[i].first) {
                ans += pq.top();
                pq.pop();
                cnt++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}