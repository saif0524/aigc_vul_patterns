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

typedef pair<int, int> pii;

int main(){
    ((void)0);
    ((void)0);
    
    int N;
    cin >> N;
    vector<pii> X(N), Y(N);
    for(int i=0;i<N;i++){
        cin >> X[i].first >> Y[i].first;
        X[i].second = i;
        Y[i].second = i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    vector<tuple<int, int, int>> edges;
    for(int i=0;i<N-1;i++){
        edges.emplace_back(abs(X[i+1].first - X[i].first), X[i].second, X[i+1].second);
        edges.emplace_back(abs(Y[i+1].first - Y[i].first), Y[i].second, Y[i+1].second);
    }
    sort(edges.begin(), edges.end());
    
    int uf[N];
    iota(uf, uf+N, 0);
    function<int(int)> find = [&](int x){ return uf[x]==x?x:uf[x]=find(uf[x]); };
    
    int ans = 0, cnt = 0;
    for(auto [w, u, v] : edges){
        int pu = find(u), pv = find(v);
        if(pu != pv){
            uf[pu] = pv;
            ans += w;
            if(++cnt == N-1) break;
        }
    }
    cout << ans;
}