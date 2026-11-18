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
    int q, x;
    cin >> q >> x;

    set<int> s;
    vector<int> a;

    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        a.push_back(y);
        s.insert(y);

        int mex = 0;
        while (s.count(mex)) {
            mex++;
        }

        int maxMex = mex;

        set<int> tmp = s;
        for (int j = 0; j < a.size(); j++) {
            int ny = a[j] % x;
            if (tmp.count(ny)) {
                tmp.erase(ny);
            } else {
                tmp.insert(ny);
            }
        }

        int nmex = 0;
        while (tmp.count(nmex % x)) {
            nmex++;
        }

        maxMex = max(maxMex, nmex);

        cout << maxMex << endl;
    }

    return 0;
}