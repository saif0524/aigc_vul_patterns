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

const int MAXN = 200005;

int n;
long long l[MAXN], r[MAXN];
vector<long long> points;
map<long long, int> mp;

int main() {
    ((void)0);
    ((void)0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        points.push_back(l[i]);
        points.push_back(r[i] + 1);
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    for (int i = 0; i < points.size(); i++) {
        mp[points[i]] = i;
    }

    vector<int> cnt(points.size(), 0);
    for (int i = 0; i < n; i++) {
        int left = mp[l[i]];
        int right = mp[r[i] + 1];
        for (int j = left; j < right; j++) {
            cnt[j]++;
        }
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] > 0 && cnt[i] <= n) {
            ans[cnt[i] - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}