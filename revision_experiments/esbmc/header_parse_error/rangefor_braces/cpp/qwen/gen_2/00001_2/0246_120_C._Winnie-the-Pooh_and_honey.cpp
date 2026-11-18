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
    int n, k;
    cin >> n >> k;
    vector<int> jars(n);
    for (int &a : jars) { cin >> a; }

    int pigletHoney = 0;
    vector<int> eatCount(n, 0);

    while (true) {
        int maxIndex = -1;
        int maxValue = 0;
        for (int i = 0; i < n; ++i) {
            if (jars[i] > maxValue && eatCount[i] < 3) {
                maxValue = jars[i];
                maxIndex = i;
            }
        }
        if (maxIndex == -1 || jars[maxIndex] < k) {
            for (int i = 0; i < n; ++i) {
                if (eatCount[i] < 3) {
                    pigletHoney += jars[i];
                }
            }
            break;
        }
        if (jars[maxIndex] >= k) {
            jars[maxIndex] -= k;
            pigletHoney += k;
            eatCount[maxIndex]++;
        }
    }

    cout << pigletHoney;
    return 0;
}