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
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<vector<int>> sub(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &sub[i][0], &sub[i][1]);
        sub[i][0]--;
        sub[i][1]--;
    }

    int max_value = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        vector<int> count(n, 0);
        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                for (int j = sub[i][0]; j <= sub[i][1]; ++j) {
                    count[j]++;
                }
            }
        }

        int value = 0;
        for (int i = 0; i < n; ++i) {
            value += a[i] * count[i];
        }

        max_value = max(max_value, value);
    }

    printf("%d\n", max_value);

    return 0;
}