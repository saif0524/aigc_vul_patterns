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

const int MAXN = 2e5 + 10;
int t, n, m, a[MAXN], b[MAXN], sum[2], cnt[2];
vector<int> one, two;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        one.clear(), two.clear(), sum[0] = 0, sum[1] = 0, cnt[0] = 0, cnt[1] = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) one.push_back(a[i]), sum[0] += a[i], cnt[0]++;
            else two.push_back(a[i]), sum[1] += a[i], cnt[1]++;
        }
        sort(one.begin(), one.end(), cmp);
        sort(two.begin(), two.end(), cmp);
        int ans = INT_MAX;
        for (int i = 0; i <= cnt[0]; i++) {
            if (sum[0] - i * one[i % cnt[0]] >= m) ans = min(ans, i);
            else {
                int tmp = m - sum[0] + i * one[i % cnt[0]];
                int low = 0, high = cnt[1];
                while (low < high) {
                    int mid = (low + high) / 2;
                    if (tmp <= i * one[i % cnt[0]] + mid * two[mid % cnt[1]]) high = mid;
                    else low = mid + 1;
                }
                if (low != cnt[1]) ans = min(ans, i + low);
            }
        }
        if (ans == INT_MAX) cout << -1 << endl;
        else cout << ans << endl;
    }
}