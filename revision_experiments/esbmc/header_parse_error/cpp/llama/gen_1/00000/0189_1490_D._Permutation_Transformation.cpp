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

const int MAXN = 101;

int a[MAXN];
map<int, int> depth;

void buildTree(int l, int r, int d) {
    if (l > r) return;
    int maxIdx = l;
    for (int i = l; i <= r; i++) {
        if (a[i] > a[maxIdx]) maxIdx = i;
    }
    depth[a[maxIdx]] = d;
    buildTree(l, maxIdx - 1, d + 1);
    buildTree(maxIdx + 1, r, d + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        depth.clear();
        buildTree(0, n - 1, 0);
        for (int i = 0; i < n; i++) {
            cout << depth[a[i]] << " ";
        }
        cout << "\n";
    }

    return 0;
}