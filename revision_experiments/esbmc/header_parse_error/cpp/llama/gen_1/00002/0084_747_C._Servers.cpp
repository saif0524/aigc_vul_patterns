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
    int n, q;
    cin >> n >> q;

    vector<int> free(n);
    for (int i = 0; i < n; ++i) {
        free[i] = i + 1;
    }

    set<pair<int, int>> busy;

    for (int i = 0; i < q; ++i) {
        int time, need, duration;
        cin >> time >> need >> duration;

        vector<int> available;
        for (int x : free) {
            available.push_back(x);
        }

        int sum = 0;
        for (int j = 0; j < need; ++j) {
            if (j < available.size()) {
                sum += available[j];
                busy.insert({time + duration, available[j]});
            } else {
                cout << "-1\n";
                goto next;
            }
        }

        for (int x : available) {
            auto it = busy.lower_bound({time, x});
            if (it != busy.end() && it->second == x) {
                free.erase(find(free.begin(), free.end(), x));
            }
        }

        free.insert(free.end(), available.begin(), available.begin() + need);

        for (int x : available) {
            auto it = busy.lower_bound({time, x});
            if (it != busy.end() && it->second == x) {
                busy.erase(it);
            }
        }

        cout << sum << "\n";

        next:;
    }

    return 0;
}