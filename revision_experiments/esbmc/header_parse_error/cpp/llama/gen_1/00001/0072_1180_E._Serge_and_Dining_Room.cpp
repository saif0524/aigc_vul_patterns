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

const int MAXN = 300005;
const int MAXPRICE = 1000005;

int n, m, q;
int a[MAXN], b[MAXN];
int cnt[MAXPRICE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    cin >> q;
    while (q--) {
        int id, x, y;
        cin >> id >> x >> y;
        if (id == 1) {
            a[x] = y;
        } else {
            b[x] = y;
        }

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= m; i++) {
            cnt[b[i]]++;
        }

        for (int i = 1; i < MAXPRICE; i++) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] %= 2;
        }

        int ans = -1;
        for (int i = MAXPRICE - 1; i >= 1; i--) {
            if (cnt[i] == 0) {
                ans = i;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}