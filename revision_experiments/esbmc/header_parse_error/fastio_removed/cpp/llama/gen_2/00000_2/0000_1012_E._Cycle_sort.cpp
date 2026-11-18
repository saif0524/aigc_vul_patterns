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

const int INF = 1e9 + 7;

int main() {
    ((void)0);
    ((void)0);

    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    vector<vector<int>> cycles;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != sorted_a[i]) {
            cnt++;
        }
    }

    if (cnt > s) {
        cout << "-1\n";
        return 0;
    }

    vector<int> p(n, -1);
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (p[j] == -1) {
            p[j] = i;
            j = distance(sorted_a.begin(), find(a.begin(), a.end(), sorted_a[j]));
        }
        if (j != i) {
            vector<int> cycle;
            while (j != i) {
                cycle.push_back(j + 1);
                p[j] = -1;
                j = distance(sorted_a.begin(), find(a.begin(), a.end(), sorted_a[j]));
            }
            cycle.push_back(i + 1);
            cycles.push_back(cycle);
            for (int ind : cycle) {
                p[ind - 1] = -1;
            }
        }
    }

    int q = cycles.size();
    cout << q << "\n";
    for (auto cycle : cycles) {
        cout << cycle.size() << "\n";
        for (int ind : cycle) {
            cout << ind << " ";
        }
        cout << "\n";
    }

    return 0;
}