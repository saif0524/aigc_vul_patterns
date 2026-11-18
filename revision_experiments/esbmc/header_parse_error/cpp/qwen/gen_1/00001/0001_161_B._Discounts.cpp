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
    int n, k;
    cin >> n >> k;
    vector<pair<long long, int>> items(n);
    for(int i=0; i<n; i++){
        cin >> items[i].first >> items[i].second;
    }
    sort(items.begin(), items.end());
    vector<int> stools;
    for(int i=0; i<n; i++){
        if(items[i].second == 1){
            stools.push_back(i+1);
        }
    }
    int st_count = 0;
    vector<vector<int>> carts(k);
    for(int i=0; i<k; i++){
        if(st_count < stools.size()){
            carts[i].push_back(stools[st_count++]);
        }
    }
    int item_index = 0;
    for(int i=0; i<k; i++){
        while(carts[i].size() < 2 && item_index < n){
            if(find(carts[i].begin(), carts[i].end(), items[item_index].first) == carts[i].end()){
                carts[i].push_back(items[item_index++].first);
            }
            else{
                item_index++;
            }
        }
    }
    while(item_index < n){
        for(int i=0; i<k && item_index < n; i++){
            if(find(carts[i].begin(), carts[i].end(), items[item_index].first) == carts[i].end()){
                carts[i].push_back(items[item_index++].first);
            }
        }
    }
    double total_cost = 0.0;
    for(int i=0; i<k; i++){
        long long min_cost = LLONG_MAX;
        for(auto &item : carts[i]){
            for(int j=0; j<n; j++){
                if(items[j].first == item){
                    min_cost = min(min_cost, items[j].first);
                    break;
                }
            }
        }
        for(auto &item : carts[i]){
            for(int j=0; j<n; j++){
                if(items[j].first == item){
                    if(items[j].first == min_cost){
                        total_cost += 0.5 * items[j].first;
                    }
                    else{
                        total_cost += items[j].first;
                    }
                    break;
                }
            }
        }
    }
    cout << fixed << setprecision(1) << total_cost << endl;
    for(int i=0; i<k; i++){
        cout << carts[i].size();
        for(auto &item : carts[i]){
            cout << " " << item;
        }
        cout << endl;
    }
}