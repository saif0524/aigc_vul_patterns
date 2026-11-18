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
    int n;
    cin >> n;
    vector<pair<int, int>> mem(n);
    for(auto &x: mem) cin >> x.first >> x.second;
    vector<vector<int>> possible(n+1);
    for(int i=0; i<n; ++i){
        for(int j=mem[i].first; j<=mem[i].second; ++j){
            possible[j].push_back(i);
        }
    }
    vector<int> order1(n), order2(n), used(n+1,0);
    bool unique = true;
    for(int i=0; i<n; ++i){
        int cnt = 0, last = -1;
        for(int j : possible[i+1]){
            if(!used[j+1]){
                ++cnt;
                last = j;
            }
        }
        if(cnt == 0){
            cout << "NO\n";
            return 0;
        }
        if(cnt > 1){
            unique = false;
        }
        used[last+1] = 1;
        order1[i] = last+1;
    }
    if(unique){
        cout << "YES\n";
        for(int x : order1) cout << x << ' ';
        cout << '\n';
    }
    else{
        cout << "NO\n";
        for(int i=0; i<n; ++i){
            int cnt = 0, last = -1;
            for(int j : possible[i+1]){
                if(!used[j+1]){
                    ++cnt;
                    last = j;
                }
            }
            used[last+1] = 1;
            order1[i] = last+1;
        }
        fill(used.begin(), used.end(), 0);
        for(int i=0; i<n; ++i){
            int cnt = 0, first = -1, last = -1;
            for(int j : possible[i+1]){
                if(!used[j+1]){
                    if(first == -1) first = j;
                    last = j;
                    ++cnt;
                }
            }
            used[first+1] = 1;
            order2[i] = first+1;
            if(cnt > 1) break;
        }
        for(int x : order1) cout << x << ' ';
        cout << '\n';
        for(int x : order2) cout << x << ' ';
        cout << '\n';
    }
}