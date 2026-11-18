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
    int n;
    cin >> n;
    vector<vector<int>> piles(n);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        piles[i].resize(s);
        for (int j = 0; j < s; ++j) {
            cin >> piles[i][j];
        }
    }

    priority_queue<pair<int, int>> pq_ciel;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_jiro;

    for (int i = 0; i < n; ++i) {
        if (!piles[i].empty()) {
            pq_ciel.push({piles[i].back(), i});
            piles[i].pop_back();
        }
        if (!piles[i].empty()) {
            pq_jiro.push({piles[i].front(), i});
            piles[i].erase(piles[i].begin());
        }
    }

    int ciel_score = 0, jiro_score = 0;
    bool ciels_turn = true;

    while (!pq_ciel.empty() || !pq_jiro.empty()) {
        if (ciels_turn && !pq_ciel.empty()) {
            auto top = pq_ciel.top();
            pq_ciel.pop();
            ciel_score += top.first;
            int idx = top.second;
            if (!piles[idx].empty()) {
                pq_ciel.push({piles[idx].back(), idx});
                piles[idx].pop_back();
            }
        } else if (!ciels_turn && !pq_jiro.empty()) {
            auto top = pq_jiro.top();
            pq_jiro.pop();
            jiro_score += top.first;
            int idx = top.second;
            if (!piles[idx].empty()) {
                pq_jiro.push({piles[idx].front(), idx});
                piles[idx].erase(piles[idx].begin());
            }
        }
        ciels_turn = !ciels_turn;
    }

    cout << ciel_score << " " << jiro_score << endl;
    return 0;
}