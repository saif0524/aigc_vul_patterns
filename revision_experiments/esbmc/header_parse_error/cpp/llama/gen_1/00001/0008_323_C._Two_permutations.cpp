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
#define int long long
using namespace std;

const int MAXN = 1e6 + 10;
int p[MAXN], q[MAXN], pos[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    for (int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
        pos[q[i]] = i;
    }

    int m; cin >> m;
    int x = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        int l1 = min((a + x) % n, (b + x) % n);
        int r1 = max((a + x) % n, (b + x) % n);
        int l2 = min((c + x) % n, (d + x) % n);
        int r2 = max((c + x) % n, (d + x) % n);

        int ans = 0;
        for (int j = l1; j <= r1; j++) {
            int num = p[j];
            if (l2 <= pos[num] && pos[num] <= r2) {
                ans++;
            }
        }

        cout << ans << '\n';
        x = ans;
    }

    return 0;
}