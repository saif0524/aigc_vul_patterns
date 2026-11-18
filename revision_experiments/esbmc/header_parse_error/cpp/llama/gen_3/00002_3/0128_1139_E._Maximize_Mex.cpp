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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 5005;

int n, m, d;
int p[MAX_N], c[MAX_N];
bool left[MAX_N];
vector<int> club[MAX_N];

int get_mex(vector<int> &v) {
    sort(v.begin(), v.end());
    int mex = 0;
    for (int x : v) {
        if (x == mex) {
            mex++;
        }
    }
    return mex;
}

int get_team_mex(int day) {
    vector<int> team;
    vector<bool> used(m + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!left[i] && !used[c[i]]) {
            team.push_back(p[i]);
            used[c[i]] = true;
        }
    }
    return get_mex(team);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        club[c[i]].push_back(p[i]);
    }
    cin >> d;
    for (int i = 1; i <= d; i++) {
        int k;
        cin >> k;
        left[k] = true;
        cout << get_team_mex(i) << "\n";
    }

    return 0;
}