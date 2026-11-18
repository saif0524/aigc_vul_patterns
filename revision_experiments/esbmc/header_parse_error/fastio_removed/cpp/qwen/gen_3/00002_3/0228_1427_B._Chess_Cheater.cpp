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
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int max_score = 0, current_score = 0, changes = 0;
        vector<int> losses;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                if (i > 0 && s[i - 1] == 'W') {
                    current_score += 2;
                } else {
                    current_score += 1;
                }
            } else {
                losses.push_back(i);
            }
        }
        int l = 0;
        for (int i = 0; i < losses.size() && changes < k; ++i) {
            int idx = losses[i];
            int gain = 2;
            if (idx > 0 && s[idx - 1] != 'W') gain--;
            if (idx < n - 1 && s[idx + 1] == 'W') gain++;
            current_score += gain;
            changes++;
            while (l < losses.size() && changes > k) {
                int prev_idx = losses[l];
                int loss = 2;
                if (prev_idx > 0 && s[prev_idx - 1] == 'W') loss--;
                if (prev_idx < n - 1 && s[prev_idx + 1] == 'W') loss++;
                current_score -= loss;
                changes--;
                l++;
            }
            max_score = max(max_score, current_score);
        }
        cout << max_score << "\n";
    }
}