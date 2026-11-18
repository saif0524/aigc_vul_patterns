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

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i].first >> dominoes[i].second;
    }

    sort(dominoes.begin(), dominoes.end());

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        int count = 1;
        int pos = dominoes[i].first;
        int height = dominoes[i].second;
        for (int j = i + 1; j < n; j++) {
            if (pos + 1 <= dominoes[j].first && dominoes[j].first <= pos + height - 1) {
                count++;
                pos = dominoes[j].first;
                height = max(height, dominoes[j].first + dominoes[j].second - 1);
            }
        }
        result[i] = count;
    }

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}