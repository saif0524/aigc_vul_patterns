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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s, t;
    cin >> n >> k >> s >> t;

    pair<int, int> cars[n];
    for (int i = 0; i < n; i++) {
        cin >> cars[i].first >> cars[i].second;
    }

    int gasStations[k];
    for (int i = 0; i < k; i++) {
        cin >> gasStations[i];
    }

    sort(gasStations, gasStations + k);
    int distances[k + 1];
    distances[0] = gasStations[0];
    for (int i = 1; i < k; i++) {
        distances[i] = gasStations[i] - gasStations[i - 1];
    }
    distances[k] = s - gasStations[k - 1];

    long long minPrice = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long time = 0;
        for (int j = 0; j <= k; j++) {
            long long distance = distances[j];
            long long fuel = min(distance, (long long)cars[i].second);
            time += min(2 * distance, fuel * 2 + (distance - fuel) * 2);
        }
        if (time <= t) {
            minPrice = min(minPrice, (long long)cars[i].first);
        }
    }

    if (minPrice == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << minPrice << endl;
    }

    return 0;
}