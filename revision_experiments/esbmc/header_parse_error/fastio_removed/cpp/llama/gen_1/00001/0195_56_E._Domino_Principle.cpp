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

const int MAXN = 1e5 + 5;

struct Domino {
    ll x, h, id;
};

bool cmp(const Domino& a, const Domino& b) {
    return a.x < b.x;
}

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    vector<Domino> dominoes(n);
    for (int i = 0; i < n; ++i) {
        cin >> dominoes[i].x >> dominoes[i].h;
        dominoes[i].id = i;
    }

    sort(dominoes.begin(), dominoes.end(), cmp);

    vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i) {
        int count = 1;
        ll currentX = dominoes[i].x;
        ll currentH = dominoes[i].h;

        for (int j = i + 1; j < n; ++j) {
            if (dominoes[j].x <= currentX + currentH - 1) {
                ++count;
                currentX = max(currentX, dominoes[j].x);
                currentH = max(currentH, dominoes[j].h);
            } else {
                break;
            }
        }

        for (int j = i - 1; j >= 0; --j) {
            if (dominoes[j].x >= dominoes[i].x - dominoes[j].h + 1) {
                ++count;
            } else {
                break;
            }
        }

        ans[dominoes[i].id] = count;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}