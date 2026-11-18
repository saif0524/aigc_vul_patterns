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

const int N = 200005;

int a[N], cnt[N], pref[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mx = 0, val;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            val = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == val) continue;

        vector<int> pos(2 * n + 1, -1);
        pos[n] = 0;

        int cur = n;
        for (int j = 1; j <= n; j++) {
            if (a[j] == val) cur--;
            if (a[j] == i) cur++;

            if (pos[cur] != -1) {
                ans = max(ans, j - pos[cur]);
            } else {
                pos[cur] = j;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}