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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) { cin >> x; }

    int max_suffix[n], max_prefix[n];
    max_suffix[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i)
        max_suffix[i] = max(a[i], max_suffix[i+1] + a[i]);

    max_prefix[0] = a[0];
    for (int i = 1; i < n; ++i)
        max_prefix[i] = max(a[i], max_prefix[i-1] + a[i]);

    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int score = 0;
        if (i > 0)
            score = max(score, max_suffix[i-1] - a[i]);
        if (i < n-1)
            score = max(score, max_prefix[i+1] - a[i]);
        ans = max(ans, score);
    }

    cout << max(ans, 0) << endl;
}