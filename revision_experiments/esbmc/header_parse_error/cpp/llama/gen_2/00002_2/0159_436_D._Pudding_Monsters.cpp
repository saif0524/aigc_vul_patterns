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

int maxSpecialCells(int n, int m, vector<int>& monsters, vector<int>& special) {
    sort(monsters.begin(), monsters.end());
    sort(special.begin(), special.end());

    int maxCount = 0;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> newMonsters;
        int count = 0;
        int last = -1;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                newMonsters.push_back(monsters[j]);
                if (last != -1) {
                    newMonsters.back() = last + 1;
                }
                last = newMonsters.back();
            } else {
                last = -1;
            }
        }

        for (int j = 0; j < m; j++) {
            if (binary_search(newMonsters.begin(), newMonsters.end(), special[j])) {
                count++;
            }
        }

        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> monsters(n);
    vector<int> special(m);

    for (int i = 0; i < n; i++) {
        cin >> monsters[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> special[i];
    }

    cout << maxSpecialCells(n, m, monsters, special) << endl;

    return 0;
}