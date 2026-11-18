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

struct Competitor {
    int s, r;
    int id;
};

bool compare(Competitor a, Competitor b) {
    if (a.s * 1.0/ a.r != b.s * 1.0 / b.r)
        return a.s *1.0 / a.r < b.s * 1.0 / b.r;
    return a.id < b.id;
}

int main() {
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<Competitor> competitors(n);
    for (int i = 0; i < n; ++i) {
        cin >> competitors[i].s >> competitors[i].r;
        competitors[i].id = i + 1;
    }
    sort(competitors.begin(), competitors.end(), compare);
    set<int> winners;
    double max_ratio = -1.0;
    for (int i = 0; i < n; ++i) {
        if (competitors[i].s * 1.0 / competitors[i].r > max_ratio) {
            winners.insert(competitors[i].id);
            max_ratio = competitors[i].s * 1.0 / competitors[i].r;
        }
    }
    for (auto it = winners.begin(); it != winners.end(); ++it) {
        if (it != winners.begin()) cout << " ";
        cout << *it;
    }
    cout << "\n";
    return 0;
}