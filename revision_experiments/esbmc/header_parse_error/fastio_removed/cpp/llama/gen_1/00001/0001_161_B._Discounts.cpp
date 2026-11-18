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

struct Item {
    long long price;
    int type;
    int index;
};

bool compareItems(const Item &a, const Item &b) {
    return a.price < b.price;
}

int main() {
    ((void)0);
    ((void)0);

    int n, k;
    cin >> n >> k;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].price >> items[i].type;
        items[i].index = i + 1;
    }

    sort(items.begin(), items.end(), compareItems);

    vector<vector<int>> carts(k);
    int stools = 0;
    for (const auto &item : items) {
        if (item.type == 1) stools++;
    }

    int cart = 0;
    for (const auto &item : items) {
        if (item.type == 1) {
            carts[cart].push_back(item.index);
            cart = (cart + 1) % k;
        }
    }

    for (const auto &item : items) {
        if (item.type == 2) {
            carts[cart].push_back(item.index);
            cart = (cart + 1) % k;
        }
    }

    long long total = 0;
    for (const auto &cartItems : carts) {
        long long minPrice = LLONG_MAX;
        long long sum = 0;
        for (const auto &itemIndex : cartItems) {
            for (const auto &item : items) {
                if (itemIndex == item.index) {
                    minPrice = min(minPrice, item.price);
                    sum += item.price;
                    break;
                }
            }
        }
        if (!cartItems.empty() && stools >= k) sum -= minPrice / 2;
        total += sum;
    }

    cout << fixed << setprecision(1) << (double)total << '\n';
    for (const auto &cartItems : carts) {
        cout << cartItems.size() << ' ';
        for (const auto &itemIndex : cartItems) {
            cout << itemIndex << ' ';
        }
        cout << '\n';
    }

    return 0;
}