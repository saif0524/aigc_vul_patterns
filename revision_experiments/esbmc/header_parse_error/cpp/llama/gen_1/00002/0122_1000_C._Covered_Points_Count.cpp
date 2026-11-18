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

const int MAXN = 2e5 + 5;

struct Segment {
    ll l, r;
};

bool cmp(const Segment& a, const Segment& b) {
    return a.l < b.l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Segment> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].l >> segs[i].r;
    }

    sort(segs.begin(), segs.end(), cmp);

    vector<ll> points;
    for (int i = 0; i < n; i++) {
        points.push_back(segs[i].l);
        points.push_back(segs[i].r + 1);
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    vector<int> cnt(n, 0);
    int idx = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        ll x = points[i];
        int cov = 0;
        while (idx < n && segs[idx].l <= x) {
            if (segs[idx].r >= x) {
                cov++;
            }
            idx++;
        }
        if (points[i + 1] - 1 >= x) {
            cnt[cov - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;

    return 0;
}