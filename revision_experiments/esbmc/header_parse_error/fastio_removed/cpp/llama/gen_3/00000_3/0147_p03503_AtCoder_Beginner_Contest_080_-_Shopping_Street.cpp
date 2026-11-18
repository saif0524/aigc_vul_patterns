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

const int MAXN = 100;
const int MAX_PERIODS = 10;

int N;
int F[MAXN + 1][MAX_PERIODS];
int P[MAXN + 1][MAX_PERIODS + 1];

int main() {
    ((void)0);
    ((void)0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < MAX_PERIODS; ++j) {
            cin >> F[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= MAX_PERIODS; ++j) {
            cin >> P[i][j];
        }
    }

    int ans = INT_MIN;
    for (int mask = 1; mask < (1 << MAX_PERIODS); ++mask) {
        int sum = 0;
        for (int i = 1; i <= N; ++i) {
            int cnt = 0;
            for (int j = 0; j < MAX_PERIODS; ++j) {
                if ((mask & (1 << j)) && F[i][j]) {
                    cnt++;
                }
            }
            sum += P[i][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';

    return 0;
}