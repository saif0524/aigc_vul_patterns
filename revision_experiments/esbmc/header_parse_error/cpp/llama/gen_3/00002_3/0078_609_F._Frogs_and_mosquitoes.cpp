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

const int N = 2e5 + 5;

struct Frog {
    int x, t, cnt;
};

bool cmp(const Frog &a, const Frog &b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Frog frogs[n];
    for (int i = 0; i < n; i++) {
        cin >> frogs[i].x >> frogs[i].t;
        frogs[i].cnt = 0;
    }

    sort(frogs, frogs + n, cmp);

    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;

        int idx = upper_bound(frogs, frogs + n, (Frog){p, INT_MAX, 0}, cmp) - frogs;
        while (idx > 0 && p <= frogs[idx - 1].x + frogs[idx - 1].t) {
            idx--;
            if (p >= frogs[idx].x && p <= frogs[idx].x + frogs[idx].t) {
                frogs[idx].t += b;
                frogs[idx].cnt++;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (frogs[j].x + frogs[j].t > frogs[j].x) {
                int k = j + 1;
                while (k < n && frogs[k].x <= frogs[j].x + frogs[j].t) {
                    if (frogs[k].x > frogs[j].x) {
                        frogs[j].t += frogs[k].t;
                        frogs[j].cnt += frogs[k].cnt;
                        frogs[k].t = 0;
                        frogs[k].cnt = 0;
                    }
                    k++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << frogs[i].cnt << " " << frogs[i].t << "\n";
    }

    return 0;
}