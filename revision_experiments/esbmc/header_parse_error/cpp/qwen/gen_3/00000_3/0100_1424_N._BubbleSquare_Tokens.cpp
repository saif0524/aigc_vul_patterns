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
    int n, k;
    cin >> n >> k;
    vector<int> deg(n+1, 0);
    vector<pair<int, int>> edges;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        deg[a]++;
        deg[b]++;
    }
    vector<pair<int, int>> sorted_deg;
    for(int i=1; i<=n; i++){
        sorted_deg.push_back({deg[i], i});
    }
    sort(sorted_deg.rbegin(), sorted_deg.rend());
    set<int> keep_token;
    int tokens = 0;
    for(auto [d, u]: sorted_deg){
        if(tokens + d*2 <= k*2){
            keep_token.insert(u);
            tokens += d*2;
        }
    }
    cout << keep_token.size() << "\n";
    for(int u: keep_token){
        cout << u << " ";
    }
    cout << "\n";
    map<pair<int, int>, int> token_dist;
    for(auto [a, b]: edges){
        if(keep_token.count(a) && keep_token.count(b)){
            token_dist[{a, b}] = 0;
        }
        else if(keep_token.count(a)){
            token_dist[{a, b}] = 2;
        }
        else if(keep_token.count(b)){
            token_dist[{a, b}] = 2;
        }
        else{
            token_dist[{a, b}] = 1;
        }
    }
    for(auto [a, b]: edges){
        cout << a << " " << b << " " << token_dist[{a, b}] << "\n";
    }
}