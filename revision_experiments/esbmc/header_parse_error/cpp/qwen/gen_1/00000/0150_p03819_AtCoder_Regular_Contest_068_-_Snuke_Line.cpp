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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> stops(M+1);
    for(int i = 0; i < N; ++i){
        int l, r;
        cin >> l >> r;
        stops[l].push_back(i);
        if(r+1 <= M) stops[r+1].push_back(-i-1);
    }
    vector<int> ans(M+1, 0);
    set<int> current;
    for(int d = 1; d <= M; ++d){
        for(int s : stops[d]){
            if(s >= 0) current.insert(s);
            else current.erase(-s-1);
        }
        ans[d] = current.size();
    }
    for(int d = 1; d <= M; ++d){
        cout << ans[d] << "\n";
    }
}