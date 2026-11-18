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

void solve(ll n, ll q, ll k, ll d) {
    vector<ll> odd, even;
    for (ll i = 1; i <= n; i += 2) odd.push_back(i);
    for (ll i = 2; i <= n; i += 2) even.push_back(i);

    vector<ll> target(n+1, -1);
    target[k] = d;

    vector<ll> current(n+1, -1);
    for (ll i = 0; i < odd.size(); ++i) current[odd[i]] = i + 1;
    for (ll i = 0; i < even.size(); ++i) current[even[i]] = odd.size() + i + 1;

    if (target == current) {
        for (ll i = 0; i < q; ++i) cout << "0\n";
        return;
    }

    vector<vector<ll>> res;
    for (ll i = 0; i < q; ++i) {
        vector<ll> new_pos(n+1);
        for (ll j = 1; j <= n; ++j) {
            if (j % 2 == 1) new_pos[current[j]] = (j+1)/2;
            else new_pos[current[j]] = odd.size() + j/2;
        }
        if (new_pos == target) {
            res.push_back(1);
            break;
        }
        current = new_pos;
        res.push_back(0);
    }

    if (res.size() != q || current != target) {
        cout << "-1\n";
        return;
    }

    for (ll op : res) cout << op << "\n";
}

int main(){
    ((void)0);
    ((void)0);
    ll n, q, k, d;
    cin >> n >> q >> k >> d;
    solve(n, q, k, d);
}