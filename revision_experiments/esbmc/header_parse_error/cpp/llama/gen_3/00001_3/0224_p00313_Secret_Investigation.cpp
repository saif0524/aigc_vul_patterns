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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y, Z;
    cin >> N;

    vector<bool> A(N + 1), B(N + 1), C(N + 1);

    cin >> X;
    for (int i = 0; i < X; ++i) {
        int a;
        cin >> a;
        A[a] = true;
    }

    cin >> Y;
    for (int i = 0; i < Y; ++i) {
        int b;
        cin >> b;
        B[b] = true;
    }

    cin >> Z;
    for (int i = 0; i < Z; ++i) {
        int c;
        cin >> c;
        C[c] = true;
    }

    set<int> result;
    for (int i = 1; i <= N; ++i) {
        if ((C[i] && !A[i]) || (C[i] && B[i])) {
            result.insert(i);
        }
    }

    cout << result.size() << '\n';

    return 0;
}