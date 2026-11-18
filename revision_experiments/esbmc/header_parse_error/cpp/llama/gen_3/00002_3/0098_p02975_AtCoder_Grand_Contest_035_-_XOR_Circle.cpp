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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int xo = 0;
    for (int i = 0; i < n; i++) xo ^= a[i];
    if (xo == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    vector<int> ans(n, -1);
    ans[0] = a[0];
    for (int i = 1; i < n; i++) {
        int ni = (a[i-1] ^ a[i]);
        if (ni == ans[i-1] || ni == 0 || binary_search(a.begin(), a.end(), ni)) ans[i] = ni;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    int no = (a[n-1] ^ a[0]);
    if (ans[n-1] != no) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}