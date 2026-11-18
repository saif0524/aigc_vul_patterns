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

int n, m;
vector<vector<int>> mat, bit;

void build_bit() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int ii = i + (i & (-i));
            if(ii <= n) {
                bit[ii][j] ^= bit[i][j];
            }
        }
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            int jj = j + (j & (-j));
            if(jj <= n) {
                bit[i][jj] ^= bit[i][j];
            }
        }
    }
}

void update(int x, int y, int val) {
    for(int i = x; i <= n; i += (i & (-i))) {
        for(int j = y; j <= n; j += (j & (-j))) {
            bit[i][j] ^= val;
        }
    }
}

int query(int x, int y) {
    int sum = 0;
    for(int i = x; i > 0; i -= (i & (-i))) {
        for(int j = y; j > 0; j -= (j & (-j))) {
            sum ^= bit[i][j];
        }
    }
    return sum;
}

int submatrixXOR(int x1, int y1, int x2, int y2) {
    return query(x2, y2) ^ query(x2, y1 - 1) ^ query(x1 - 1, y2) ^ query(x1 - 1, y1 - 1);
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m;
    mat = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    bit = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    int type, x1, y1, x2, y2, v;
    while(m--) {
        cin >> type;
        if(type == 2) {
            cin >> x1 >> y1 >> x2 >> y2 >> v;
            update(x1, y1, v);
            update(x1, y2 + 1, v);
            update(x2 + 1, y1, v);
            update(x2 + 1, y2 + 1, v);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << submatrixXOR(x1, y1, x2, y2) << "\n";
        }
    }
}