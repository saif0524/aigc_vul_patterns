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

const int N = 1e6 + 5;

int n, m;
int a[N], b[N];

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> idx(1000001, -1);
    for (int i = 0; i < m; i++) {
        idx[b[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int len = 0;
        int pos = i;
        for (int j = 0; j < n; j++) {
            if (idx[a[pos]] == -1) {
                break;
            }
            len++;
            pos = (pos + 1) % n;
            int nextPos = idx[a[pos]];
            while (nextPos < idx[a[pos - 1]] && nextPos != -1) {
                nextPos = idx[b[nextPos + 1]];
            }
            if (nextPos == -1) {
                break;
            }
            idx[a[pos - 1]] = nextPos;
        }
        ans = max(ans, len);
    }

    cout << ans << '\n';

    return 0;
}