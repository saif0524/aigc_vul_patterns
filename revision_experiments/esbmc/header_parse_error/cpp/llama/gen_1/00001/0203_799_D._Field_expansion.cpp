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

int solve(int a, int b, int h, int w, vector<int>& extensions) {
    if (a <= h && b <= w || a <= w && b <= h) return 0;

    sort(extensions.rbegin(), extensions.rend());
    int result = INT_MAX;
    for (int i = 1; i <= extensions.size(); i++) {
        for (int j = 0; j < i; j++) {
            int newH = h;
            int newW = w;
            for (int k = 0; k < i; k++) {
                if (k <= j) newH *= extensions[k];
                else newW *= extensions[k];
            }
            if (a <= newH && b <= newW || a <= newW && b <= newH) {
                result = min(result, i);
            }
        }
    }
    return result == INT_MAX ? -1 : result;
}

int main() {
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> extensions(n);
    for (int i = 0; i < n; i++) {
        cin >> extensions[i];
    }
    cout << solve(a, b, h, w, extensions) << endl;
    return 0;
}