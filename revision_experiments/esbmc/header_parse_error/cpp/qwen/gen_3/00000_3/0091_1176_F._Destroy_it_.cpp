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
    int n;
    cin >> n;
    vector<vector<pair<int, long long>>> turns(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        turns[i].resize(k);
        for(int j=0; j<k; j++){
            cin >> turns[i][j].first >> turns[i][j].second;
        }
        sort(turns[i].begin(), turns[i].end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
    }
    long long total_damage = 0;
    long long card_count = 0;
    for(int i=0; i<n; i++){
        long long budget = 3;
        for(auto& [cost, damage] : turns[i]){
            if(budget >= cost){
                budget -= cost;
                card_count++;
                if(card_count % 10 == 0){
                    total_damage += 2 * damage;
                }
                else{
                    total_damage += damage;
                }
            }
            if(budget == 0){
                break;
            }
        }
    }
    cout << total_damage;
}