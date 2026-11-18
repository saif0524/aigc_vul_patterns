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

struct Interval {
    long long l, r;
};

bool operator<(const Interval& a, const Interval& b) {
    if (a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long L;
    cin >> N >> L;
    vector<Interval> intervals(N);
    for (auto& [l, r] : intervals) cin >> l >> r;

    sort(intervals.begin(), intervals.end());

    long long x = 0, cv = 0;
    priority_queue<long long> pq;
    for (const auto& [l, r] : intervals) {
        if (l > cv) {
            x++;
            cv = r;
            while (!pq.empty() && pq.top() <= cv) pq.pop();
        }
        pq.push(r);
    }

    vector<long long> yValues;
    long long lastR = 0;
    for (const auto& [l, r] : intervals) {
        if (l > lastR) yValues.push_back(lastR);
        lastR = max(lastR, r);
    }
    yValues.push_back(lastR);

    long long y = 0;
    for (long long i = 0; i < (1LL << N); i++) {
        long long cv = 0;
        for (int j = 0; j < N; j++) {
            if ((i & (1LL << j)) != 0) {
                cv = max(cv, intervals[j].r);
            }
        }
        if (cv >= L) y++;
    }
    y = N - (long long)count_if(yValues.begin(), yValues.end(), [&](long long x) { return x < L; }) + 1;

    cout << x << " " << y << endl;

    return 0;
}