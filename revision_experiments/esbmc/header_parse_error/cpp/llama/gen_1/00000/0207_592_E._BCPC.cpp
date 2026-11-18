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

struct Student {
    int id;
    long long r, w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c, d;
    cin >> n >> c >> d;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].r >> students[i].w;
        students[i].r -= c;
        students[i].w -= d;
        students[i].id = i;
    }

    vector<pair<long long, long long>> points;
    for (const auto& s : students) {
        points.push_back({s.r, s.w});
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> above, below;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (students[i].r * students[j].w > students[j].r * students[i].w) {
                above.push_back(j);
            } else {
                below.push_back(j);
            }
        }

        for (const auto& j : above) {
            for (const auto& k : below) {
                if (students[j].r * students[k].w > students[k].r * students[j].w &&
                    students[k].r * students[i].w > students[i].r * students[k].w) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}