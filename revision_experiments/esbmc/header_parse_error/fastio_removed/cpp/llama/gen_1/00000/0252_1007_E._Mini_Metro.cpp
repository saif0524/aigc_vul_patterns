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
using ll = long long;

int main() {
    ((void)0);
    ((void)0);

    int n, t, k;
    cin >> n >> t >> k;

    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<int> ans(t, 0);
    for (int i = 0; i < t; ++i) {
        vector<ll> curr = a;
        for (int j = 0; j < n; ++j) {
            curr[j] += b[j] * (i + 1);
        }

        int trains = 0;
        ll cap = 0;
        for (int j = 0; j < n; ++j) {
            if (curr[j] > c[j]) {
                ll need = curr[j] - c[j];
                if (cap >= need) {
                    cap -= need;
                    curr[j] = c[j];
                } else {
                    need -= cap;
                    trains += (need + k - 1) / k;
                    cap = k - (need % k);
                    if (cap == k) cap = 0;
                    curr[j] -= need;
                }
            }

            if (cap == 0) {
                int take = min(curr[j], k);
                cap += k - take;
                curr[j] -= take;
            }
        }

        ans[i] = trains;
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;

    return 0;
}