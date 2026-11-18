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

    int N;
    cin >> N;

    vector<pair<long long, long long>> vec;
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        vec.push_back({a * (1LL << b), 1LL << b});
    }

    sort(vec.begin(), vec.end());

    vector<long long> weights;
    vector<long long> counts;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += vec[i].first;
        weights.push_back(sum);
        counts.push_back(vec[i].second);
    }

    vector<long long> result;

    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && weights[j] - weights[i] < counts[i]) j++;

        long long totalWeight = weights[j - 1] - weights[i] + vec[j - 1].first;
        long long totalMarg = vec[j - 1].second;

        while (totalWeight % (totalMarg * 2)) {
            totalMarg *= 2;
        }

        result.push_back({totalWeight / totalMarg, __builtin_ctzll(totalMarg)});
        i = j;
    }

    sort(result.begin(), result.end());

    for (auto& p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}