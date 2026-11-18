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

const int MAXN = 4e5 + 5;
int n, I, a[MAXN];
map<int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> I;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<pair<int, int>> v;
    for (auto& it : cnt) {
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end());

    int k = 8 * I / n;
    int K = pow(2, k);

    if (v.size() <= K) {
        cout << 0 << endl;
        return 0;
    }

    int ans = n;
    int l = 0, r = v.size() - K;
    for (int i = 0; i <= v.size() - K; ++i) {
        int sum = 0;
        for (int j = 0; j < l; ++j) {
            sum += v[j].second;
        }
        for (int j = r + 1; j < v.size(); ++j) {
            sum += v[j].second;
        }
        ans = min(ans, sum);
        l++, r++;
    }

    cout << ans << endl;

    return 0;
}