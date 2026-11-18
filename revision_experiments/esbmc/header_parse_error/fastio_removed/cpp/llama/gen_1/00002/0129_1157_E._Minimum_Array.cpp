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

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i] = {a[i], i};
    }

    sort(vp.begin(), vp.end());
    sort(b.begin(), b.end());

    vector<int> ind(n), ans(n);
    for (int i = 0; i < n; i++) {
        ind[vp[i].second] = i;
    }

    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                if ((a[ind[i]] + b[j]) % n < (a[ind[i]] + b[used[j]]) % n) {
                    ans[ind[i]] = b[j];
                    used[j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (a[i] + ans[i]) % n << " ";
    }

    return 0;
}