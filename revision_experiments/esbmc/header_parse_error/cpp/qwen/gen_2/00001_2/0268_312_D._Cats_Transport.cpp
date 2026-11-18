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

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
        cin >> d[i];
    }
    vector<long long> dist(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        dist[i] = dist[i - 1] + d[i - 1];
    }
    vector<pair<long long, int>> cats(m);
    for (auto &cat : cats) {
        cin >> cat.second >> cat.first;
    }
    sort(cats.begin(), cats.end());
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int cat_index = 0;
    for (int time = 0; cat_index < m || !pq.empty(); time++) {
        while (cat_index < m && cats[cat_index].first == time) {
            pq.push(dist[cats[cat_index].second] - time);
            cat_index++;
        }
        if (!pq.empty() && pq.size() <= p) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}