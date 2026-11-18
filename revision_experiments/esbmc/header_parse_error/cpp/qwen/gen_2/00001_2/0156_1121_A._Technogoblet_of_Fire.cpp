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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    for (int &x : p) cin >> x;
    vector<int> s(n);
    for (int &x : s) cin >> x;
    vector<int> c(k);
    for (int &x : c) {
        cin >> x;
        x--;
    }
    
    vector<vector<int>> school(m);
    for (int i = 0; i < n; ++i) {
        school[s[i] - 1].push_back(i);
    }
    
    int cnt = 0;
    for (int id : c) {
        int max_pow = p[id];
        bool found = false;
        for (int student : school[s[id] - 1]) {
            if (p[student] > max_pow) {
                found = true;
                break;
            }
        }
        if (found) cnt++;
    }
    
    cout << cnt;
}