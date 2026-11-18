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

int n, q;
vector<int> a;

bool check(int i, int j, int k) {
    return (a[i] <= a[j] && a[j] <= a[k]) || (a[i] >= a[j] && a[j] >= a[k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        vector<int> ans;
        for (int i = l; i <= r; ++i) {
            bool ok = true;
            for (int j = l; j < i; ++j) {
                for (int k = i + 1; k <= r; ++k) {
                    if (check(j, i, k)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) ans.push_back(i + 1);
        }

        if (ans.size() <= 2) {
            cout << "0\n";
        } else {
            cout << ans.size() << "\n";
            for (int x : ans) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}