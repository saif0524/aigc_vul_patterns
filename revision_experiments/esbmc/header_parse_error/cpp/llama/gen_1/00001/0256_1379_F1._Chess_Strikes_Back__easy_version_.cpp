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

const int N = 1e6 + 5;

int n, m, q;
int g[200020][200020];
int col1[200020], col2[200020];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> q;
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * m; ++j) {
            g[i][j] = 1;
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        g[r][c] = 0;
        if ((r + c) % 2 == 0) {
            if (r % 2 == 1) {
                col1[c]++;
            } else {
                col2[c]++;
            }
        }

        bool yes = true;

        for (int c = 1; c <= 2 * m; ++c) {
            if (col1[c] > m) {
                yes = false;
                break;
            }
            if (col2[c] > m) {
                yes = false;
                break;
            }
        }

        if (yes) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}