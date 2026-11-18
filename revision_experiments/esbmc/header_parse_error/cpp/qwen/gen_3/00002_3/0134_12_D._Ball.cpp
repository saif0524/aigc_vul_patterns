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
    int N;
    cin >> N;
    vector<pair<int, pair<int, int>>> ladies(N);
    for(int i = 0; i < N; ++i) cin >> ladies[i].first;
    for(int i = 0; i < N; ++i) cin >> ladies[i].second.first;
    for(int i = 0; i < N; ++i) cin >> ladies[i].second.second;
    sort(ladies.begin(), ladies.end());
    int ans = 0;
    set<int> st;
    for(int i = N-1; i >= 0; --i){
        int b = ladies[i].first, iq = ladies[i].second.first, r = ladies[i].second.second;
        auto it = st.lower_bound(iq);
        if(it != st.end() && *it > r) ++ans;
        else st.insert(r);
    }
    cout << ans;
}