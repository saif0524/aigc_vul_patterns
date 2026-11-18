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

bool can_visit_all_oases(int start, vector<long long> &oases, int V) {
    int N = oases.size();
    vector<bool> visited(N, false);
    visited[start] = true;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, start});
    int remaining = N - 1;
    int current_volume = V;

    while (!pq.empty() && remaining) {
        auto [distance, idx] = pq.top();
        pq.pop();
        long long current_oasis = oases[idx];

        if (current_volume < (oases[N-1] - current_oasis)) {
            current_volume = V / 2;
        }

        for (int next = 0; next < N; ++next) {
            if (visited[next]) continue;
            long long next_oasis = oases[next];
            long long required_water = abs(next_oasis - current_oasis);
            if (required_water <= current_volume) {
                visited[next] = true;
                remaining--;
                pq.push({distance + required_water, next});
                current_volume -= required_water;
                break;
            }
        }

        if (current_volume == 0) {
            current_volume = V / 2;
        }
    }

    return remaining == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, V;
    cin >> N >> V;
    vector<long long> oases(N);
    for (auto &x : oases) cin >> x;
    for (int i = 0; i < N; ++i){
        if (can_visit_all_oases(i, oases, V)){
            cout << "Possible\n";
        }
        else{
            cout << "Impossible\n";
        }
    }
}