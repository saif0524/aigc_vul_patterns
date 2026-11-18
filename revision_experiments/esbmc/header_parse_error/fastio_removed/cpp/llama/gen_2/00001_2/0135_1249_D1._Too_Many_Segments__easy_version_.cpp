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

const int maxn = 210;

int n, k, l[maxn], r[maxn], cnt[maxn];
bool del[maxn];

bool cmp(int a, int b) {
    return l[a] < l[b] || (l[a] == l[b] && r[a] < r[b]);
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    int ans = 1e9;
    vector<int> pos;

    do {
        memset(del, 0, sizeof(del));
        for (int i = 1; i <= n; i++) {
            if (!del[i]) {
                for (int j = l[i]; j <= r[i]; j++) {
                    cnt[j]++;
                }
            }
        }

        int badPoint = 0;
        for (int i = 1; i <= 200; i++) {
            if (cnt[i] > k) {
                badPoint++;
            }
        }

        for (int i = 1; i <= 200; i++) {
            cnt[i] = 0;
        }

        if (badPoint == 0) {
            int cntDel = 0;
            for (int i = 1; i <= n; i++) {
                if (del[i]) {
                    cntDel++;
                }
            }
            if (cntDel < ans) {
                ans = cntDel;
                pos.clear();
                for (int i = 1; i <= n; i++) {
                    if (del[i]) {
                        pos.push_back(i);
                    }
                }
            }
        } else {
            int minIdx = -1, maxCnt = -1;
            for (int i = 1; i <= n; i++) {
                if (del[i]) {
                    continue;
                }
                int curCnt = 0;
                memset(cnt, 0, sizeof(cnt));
                for (int j = 1; j <= n; j++) {
                    if (del[j] || j == i) {
                        continue;
                    }
                    for (int t = l[j]; t <= r[j]; t++) {
                        cnt[t]++;
                    }
                }
                for (int j = l[i]; j <= r[i]; j++) {
                    cnt[j]++;
                }
                for (int j = 1; j <= 200; j++) {
                    if (cnt[j] > k) {
                        curCnt++;
                    }
                }
                if (curCnt < badPoint) {
                    badPoint = curCnt;
                    minIdx = i;
                }
            }
            del[minIdx] = 1;
        }
    } while (next_permutation(del + 1, del + n + 1));

    cout << ans << '\n';
    for (int x : pos) {
        cout << x << " ";
    }
    return 0;
}