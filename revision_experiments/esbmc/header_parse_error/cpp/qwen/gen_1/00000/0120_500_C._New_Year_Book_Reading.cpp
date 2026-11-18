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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for(auto &x : w) cin >> x;
    vector<int> b(m);
    for(auto &x : b) cin >> x;

    long long ans = LLONG_MAX;
    do {
        long long total = 0;
        vector<int> pos(n+1);
        for(int i = 0; i < n; ++i) pos[w[i]] = i;
        for(int day = 0, top = 0; day < m; ++day){
            int book = b[day];
            for(int i = top; i < pos[book]; ++i){
                total += w[i];
            }
            top = pos[book]+1;
            for(int i = pos[book]; i > top; --i){
                swap(w[i], w[i-1]);
                pos[w[i]]++;
                pos[w[i-1]]--;
            }
        }
        ans = min(ans, total);
    } while(next_permutation(w.begin(), w.end()));

    cout << ans;
}