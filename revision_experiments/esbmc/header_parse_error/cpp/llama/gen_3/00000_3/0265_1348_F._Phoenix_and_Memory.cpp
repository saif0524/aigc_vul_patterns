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

const int N = 2e5 + 5;

int n, seq[N];
pair<pair<int, int>, int> mem[N];

bool solve() {
    vector<vector<int>> possible(N);
    for (int i = 0; i < n; i++) {
        possible[mem[i].first.first].push_back(i);
    }

    set<int> assigned;
    for (int i = 1; i <= n; i++) {
        vector<int> can;
        for (auto j : possible[i]) {
            if (assigned.find(mem[j].second) != assigned.end()) {
                continue;
            }
            can.push_back(j);
        }

        if (can.size() > 1) {
            return false;
        }
        if (can.size() == 1) {
            assigned.insert(mem[can[0]].second);
            seq[i - 1] = mem[can[0]].second;
        }
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mem[i].first.first >> mem[i].first.second;
        mem[i].second = i;
    }
    sort(mem, mem + n);

    if (solve()) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << seq[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
        vector<int> x(n), y(n);
        bool first = true;
        for (int i = 0; i < n; i++) {
            y[i] = x[i] = seq[i];
        }
        pair<int, int> found;
        for (int i = 0; i < n; i++) {
            if (mem[i].first.second - mem[i].first.first >= 1) {
                seq[mem[i].first.first - 1] = mem[i].second;
                pair<int, int> test;
                test.first = mem[i].first.first;
                test.second = mem[i].first.second;
                if (first) {
                    for (int j = test.first; j <= test.second; j++) {
                        if (j != test.first) {
                            found = {j, mem[i].second};
                            first = false;
                            break;
                        }
                    }
                } else {
                    for (int j = test.second; j >= test.first; j--) {
                        if (j != test.first) {
                            int tmp = mem[i].second;
                            x[test.first - 1] = found.second;
                            y[found.first - 1] = tmp;
                            goto out;
                        }
                    }
                }
            }
        }
out:
        for (int i = 0; i < n; i++) {
            cout << x[i] + 1 << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << y[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}