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

typedef long long ll;
typedef pair<int, int> pii;

const int MAX_N = 5005;
const int MAX_M = 20005;

int n, m;
vector<int> a[MAX_N], b[MAX_N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int ai, bi;
        cin >> ai >> bi;
        a[ai].push_back(bi);
        b[bi].push_back(ai);
    }

    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
    }

    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        vector<int> dst;
        for (int j = 1; j <= m; j++) {
            int start = (i + n - 1) % n + 1;
            int end = a[start].back();
            a[start].pop_back();
            int loop = max(0, end - start);
            ans += loop + 1;
            dst.push_back(end);
        }
        sort(dst.begin(), dst.end());
        while (dst.size() > 0 && dst[0] == i) {
            dst.erase(dst.begin());
        }
        if (dst.size() > 0) {
            int end = dst[0];
            int loop = max(0, end - i);
            ans += loop + 1;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}