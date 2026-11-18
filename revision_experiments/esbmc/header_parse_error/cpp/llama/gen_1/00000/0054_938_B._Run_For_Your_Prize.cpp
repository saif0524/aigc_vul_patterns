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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt1 = 0, cnt2 = 0;
        int last1 = 1, last2 = 1000000000;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                cnt1 += abs(a[i] - last1);
                last1 = a[i];
            } else {
                cnt2 += abs(a[i] - last2);
                last2 = a[i];
            }
        }
        ans = min(ans, max(cnt1, cnt2));
    }
    cout << ans << '\n';
    return 0;
}