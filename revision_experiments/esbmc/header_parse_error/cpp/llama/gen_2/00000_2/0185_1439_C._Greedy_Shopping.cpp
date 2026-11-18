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

const int MAXN = 2e5 + 5;
int n, q;
int arr[MAXN];

void update(int x, int y) {
    for (int i = 1; i <= x; i++) {
        arr[i] = max(arr[i], y);
    }
}

void query(int x, int y) {
    int ans = 0;
    for (int i = x; i <= n; i++) {
        if (y >= arr[i]) {
            ans++;
            y -= arr[i];
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(x, y);
        } else {
            query(x, y);
        }
    }
    return 0;
}