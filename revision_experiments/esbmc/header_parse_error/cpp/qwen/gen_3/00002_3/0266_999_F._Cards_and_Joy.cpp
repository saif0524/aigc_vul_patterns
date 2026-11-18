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
    vector<int> c(n*k);
    for(auto &x: c) cin >> x;
    vector<int> f(n);
    for(auto &x: f) cin >> x;
    vector<int> h(k);
    for(auto &x: h) cin >> x;
    vector<int> fav_count(100005, 0);
    for(int i=0;i<n;++i){
        fav_count[f[i]]++;
    }
    vector<int> card_count(100005, 0);
    for(auto &x: c){
        if(fav_count[x]>0){
            card_count[x]++;
        }
    }
    vector<int> fav_with_cards;
    for(int i=0;i<100005;++i){
        if(card_count[i]>0){
            fav_with_cards.push_back(i);
        }
    }
    int total_joy = 0;
    for(auto &x: fav_with_cards){
        int min_assign = min(k, card_count[x]);
        for(int j=min_assign;j>=1;--j){
            if(fav_count[x]>0){
                total_joy += h[j-1];
                fav_count[x]--;
                card_count[x] -= j;
            }
        }
    }
    cout << total_joy;
}