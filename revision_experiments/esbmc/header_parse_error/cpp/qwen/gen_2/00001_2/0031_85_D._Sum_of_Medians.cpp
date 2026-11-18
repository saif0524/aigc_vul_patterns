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

const int MAXN = 1e5 + 10;
multiset<int> S;
int medians[MAXN];
int med_cnt = 0;

int find_median(multiset<int>::iterator &it) {
    auto start = it;
    advance(start, -2);
    return *next(start, 2);
}

void update_medians() {
    med_cnt = 0;
    for (auto it = S.begin(); it != S.end(); ) {
        medians[med_cnt++] = find_median(it);
        advance(it, 5);
    }
}

long long sum_of_medians() {
    long long sum = 0;
    for (int i = 0; i < med_cnt; ++i) {
        sum += medians[i];
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "add") {
            int x;
            cin >> x;
            auto it = S.insert(x);
            if (it == S.begin() || *prev(it) != x) {
                update_medians();
            }
        } else if (op == "del") {
            int x;
            cin >> x;
            auto it = S.find(x);
            if (it != S.end()) {
                S.erase(it);
                if (it == S.begin() || *prev(it) != x) {
                    update_medians();
                }
            }
        } else {
            if (S.empty()) {
                cout << 0 << "\n";
            } else {
                cout << sum_of_medians() << "\n";
            }
        }
    }
    return 0;
}