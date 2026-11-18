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
const int MAX = 105;
vector<int> x[MAX], y[MAX];
int n;

bool is_special_case(int u, int v) {
    if (u == v) return false;
    if (x[u].size() == 0) return false;
    if (x[u].back() == v) return true;
    for (int w : x[u]) {
        if (is_special_case(w, v)) return true;
    }
    return false;
}

bool is_part_of(int u, int v) {
    if (u == v) return false;
    if (y[v].size() == 0) return false;
    if (y[v].back() == u) return true;
    for (int w : y[v]) {
        if (is_special_case(w, v)) {
            if (is_part_of(u, w)) return true;
        }
    }
    for (int w : x[v]) {
        if (is_part_of(u, w)) return true;
    }
    return false;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int par, typ;
        cin >> par >> typ;
        if (par != -1) {
            if (typ == 0) {
                x[par].push_back(i + 1);
            } else {
                y[i + 1].push_back(par);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int typ, u, v;
        cin >> typ >> u >> v;
        bool ans = false;
        if (typ == 1) {
            ans = is_special_case(u, v);
        } else {
            ans = is_part_of(u, v);
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}