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
    vector<pair<int,int>> segments(n);
    for(int i=0; i<n; ++i){
        cin >> segments[i].first >> segments[i].second;
    }
    
    vector<int> remove;
    for(int i=0; i<n; ++i){
        vector<int> cnt(201, 0);
        int bad = 0;
        for(int j=0; j<n; ++j){
            if(i != j){
                for(int p=segments[j].first; p<=segments[j].second; ++p){
                    cnt[p]++;
                    if(cnt[p] == k+1){
                        bad++;
                    }
                }
            }
        }
        if(bad == 0){
            continue;
        }
        remove.push_back(i);
        for(int j=segments[i].first; j<=segments[i].second; ++j){
            for(int x=0; x<n; ++x){
                if(x != i){
                    int start = segments[x].first, end = segments[x].second;
                    if(start <= j && j <= end){
                        bad--;
                        break;
                    }
                }
            }
        }
        if(bad == 0){
            break;
        }
    }
    
    cout << remove.size() << "\n";
    for(int i=0; i<remove.size(); ++i){
        cout << (remove[i] + 1) << (i < remove.size() - 1 ? ' ' : '\n');
    }
    return 0;
}