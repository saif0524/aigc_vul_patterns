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
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> D(N);
    for(auto &d : D) { cin >> d; }
    
    int bestCalPerDollar = 0;
    for(int mask = 0; mask < (1 << N); mask++) {
        int totalCalories = C;
        int totalPrice = A;
        for(int i = 0; i < N; i++) {
            if(mask & (1 << i)) {
                totalCalories += D[i];
                totalPrice += B;
            }
        }
        bestCalPerDollar = max(bestCalPerDollar, totalCalories / totalPrice);
    }
    
    cout << bestCalPerDollar;
}