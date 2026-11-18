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
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> edges(m, 0);
        vector<int> used(3 * n, 0);
        vector<int> matching;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (!used[u] && !used[v]) {
                matching.push_back(i + 1);
                used[u] = 1;
                used[v] = 1;
                if (matching.size() == n) break;
            }
            edges[i] = max(u, v);
        }
        if (matching.size() == n) {
            cout << "Matching\n";
            for (int i : matching) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            vector<int> IndependentSet;
            for (int i = 0; i < 3 * n; ++i) {
                if (!used[i]) {
                    IndependentSet.push_back(i + 1);
                }
                if (IndependentSet.size() == n) break;
            }
            cout << "IndSet\n";
            for (int i : IndependentSet) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}