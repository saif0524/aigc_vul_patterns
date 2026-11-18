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

vector<int> median_smoothing(const vector<int>& a) {
    int n = a.size();
    vector<int> b(n);
    b[0] = a[0];
    b[n-1] = a[n-1];
    for (int i = 1; i < n - 1; ++i) {
        int x = a[i-1], y = a[i], z = a[i+1];
        vector<int> med = {x, y, z};
        sort(med.begin(), med.end());
        b[i] = med[1];
    }
    return b;
}

bool is_stable(const vector<int>& a, const vector<int>& b) {
    return a == b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a) cin >> x;
    int steps = 0;
    vector<int> b = median_smoothing(a);
    while(!is_stable(a, b)){
        a = b;
        b = median_smoothing(a);
        steps++;
        if(steps > n) {
            cout << -1;
            return 0;
        }
    }
    cout << steps << "\n";
    for(int x: b) cout << x << " ";
    cout << "\n";
}