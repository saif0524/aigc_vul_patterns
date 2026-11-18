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

struct Diamond {
    ll weight;
    ll value;
    ll count;
};

bool compareDiamonds(const Diamond& d1, const Diamond& d2) {
    if (d1.value != d2.value) {
        return d1.value > d2.value;
    } else if (d1.weight != d2.weight) {
        return d1.weight < d2.weight;
    }
    return false;
}

int main() {
    ll n, q;
    cin >> n >> q;

    vector<Diamond> diamonds(n);
    for (int i = 0; i < n; ++i) {
        cin >> diamonds[i].count >> diamonds[i].weight >> diamonds[i].value;
    }

    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll k, d;
            cin >> k >> d;
            diamonds[d - 1].count += k;
        } else if (t == 2) {
            ll k, d;
            cin >> k >> d;
            diamonds[d - 1].count -= k;
        } else {
            ll c;
            cin >> c;

            vector<Diamond> diamondList;
            for (const auto& diamond : diamonds) {
                for (int i = 0; i < diamond.count; ++i) {
                    diamondList.push_back({diamond.weight, diamond.value, 1});
                }
            }

            sort(diamondList.begin(), diamondList.end(), compareDiamonds);

            ll value = 0;
            for (const auto& diamond : diamondList) {
                if (c >= diamond.weight) {
                    c -= diamond.weight;
                    value += diamond.value;
                } else {
                    break;
                }
            }

            cout << value << endl;
        }
    }

    return 0;
}