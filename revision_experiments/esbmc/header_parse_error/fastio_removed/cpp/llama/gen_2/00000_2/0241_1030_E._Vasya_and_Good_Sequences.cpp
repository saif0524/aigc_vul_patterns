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

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int l = 0; l < n; l++) {
        vector<int> cnt(100, 0);
        for (int r = l; r < n; r++) {
            int bits = __builtin_popcountll(a[r]);
            cnt[bits]++;
            int sum = 0;
            bool ok = true;
            for (int i = 1; i < 100; i++) {
                if (cnt[i] % 2 == 1) {
                    if (sum == 0) {
                        sum = i;
                    } else {
                        ok = sum >= i;
                        if (!ok) break;
                        sum = sum - i;
                    }
                }
            }
            if (ok) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}