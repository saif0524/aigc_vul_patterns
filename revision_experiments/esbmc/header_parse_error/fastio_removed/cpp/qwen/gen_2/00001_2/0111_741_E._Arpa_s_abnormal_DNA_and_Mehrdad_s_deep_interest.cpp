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
    string S, T;
    int q;
    cin >> S >> T >> q;
    int n = S.size(), m = T.size();
    vector<vector<int>> hashes(n + 1, vector<int>(26));
    vector<int> pws(n + 1);
    pws[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 26; ++j) {
            hashes[i][j] = hashes[i - 1][j];
        }
        hashes[i][S[i - 1] - 'a']++;
        pws[i] = (pws[i - 1] * 131) % 998244353;
    }

    auto getHash = [&](int l, int r) {
        if(l > r) return 0;
        int res = 0;
        for(int j = 0; j < 26; ++j) {
            res = (res * 131 + (hashes[r][j] - hashes[l - 1][j] + 998244353) % 998244353) % 998244353;
        }
        return res;
    };

    while(q--) {
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;
        int ans = -1;
        for(int i = l; i <= r; ++i) {
            int nh = getHash(1, i - 1);
            int ah = 0;
            for(int j = x + 1; j <= y; ++j) {
                ah = (ah + pws[m - j] * (T[j - 1] - 'a')) % 998244353;
            }
            nh = (nh * pws[m - x - 1] + ah) % 998244353;
            nh = (nh * pws[r - i + 1] + getHash(i + 1, r)) % 998244353;
            if(ans == -1 || nh < (int)getHash(1, n)) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
}