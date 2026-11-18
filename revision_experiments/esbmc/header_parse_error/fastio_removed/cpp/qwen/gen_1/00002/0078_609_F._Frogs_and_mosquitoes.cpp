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
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> frogs(n);
    for(auto &x: frogs) cin >> x.first >> x.second;
    vector<pair<long long, long long>> mosquitoes(m);
    for(auto &x: mosquitoes) cin >> x.first >> x.second;
    sort(frogs.begin(), frogs.end());
    sort(mosquitoes.begin(), mosquitoes.end());
    int frog_idx = 0;
    int mosquito_idx = 0;
    vector<pair<int, long long>> result(n, {0, 0});
    while(frog_idx < n && mosquito_idx < m){
        if(frogs[frog_idx].first <= mosquitoes[mosquito_idx].first && 
           mosquitoes[mosquito_idx].first <= frogs[frog_idx].first + frogs[frog_idx].second){
            result[frog_idx].first++;
            result[frog_idx].second += mosquitoes[mosquito_idx].second;
            frogs[frog_idx].second = result[frog_idx].second;
            mosquito_idx++;
        }
        else{
            frog_idx++;
        }
    }
    frog_idx = 0;
    mosquito_idx = 0;
    while(frog_idx < n && mosquito_idx < m){
        while(mosquito_idx < m && frogs[frog_idx].first > mosquitoes[mosquito_idx].first){
            mosquito_idx++;
        }
        while(frog_idx < n && mosquito_idx < m && frogs[frog_idx].first <= mosquitoes[mosquito_idx].first && 
              mosquitoes[mosquito_idx].first <= frogs[frog_idx].first + frogs[frog_idx].second){
            result[frog_idx].first++;
            result[frog_idx].second += mosquitoes[mosquito_idx].second;
            frogs[frog_idx].second = result[frog_idx].second;
            mosquito_idx++;
        }
        frog_idx++;
    }
    for(auto &x: result){
        cout << x.first << " " << x.second << "\n";
    }
}