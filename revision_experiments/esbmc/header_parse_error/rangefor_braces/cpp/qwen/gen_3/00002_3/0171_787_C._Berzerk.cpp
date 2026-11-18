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

int n;
vector<int> s1, s2;

bool check(vector<int>& s, int start) {
    unordered_set<int> visited;
    int pos = start;
    while (true) {
        if (pos == 0) return true;
        if (visited.find(pos) != visited.end()) return false;
        visited.insert(pos);
        int next_pos = -1;
        for (int step : s) {
            int new_pos = (pos + step) % n;
            if (next_pos == -1 || (abs(new_pos - pos) < abs(next_pos - pos))) {
                next_pos = new_pos;
            }
        }
        pos = next_pos;
    }
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n;
    int k1;
    cin >> k1;
    s1.resize(k1);
    for (int &x : s1) { cin >> x; }
    int k2;
    cin >> k2;
    s2.resize(k2);
    for (int &x : s2) { cin >> x; }
    for (int first = 0; first < 2; ++first) {
        for (int start = 1; start < n; ++start) {
            bool win = check(first == 0 ? s1 : s2, start);
            bool lose = true;
            for (int step : (first == 0 ? s1 : s2)) {
                if (check(first == 1 ? s1 : s2, (start + step) % n)) {
                    lose = false;
                    break;
                }
            }
            if (win) cout << "Win ";
            else if (lose) cout << "Lose ";
            else cout << "Loop ";
        }
        cout << "\n";
    }
}