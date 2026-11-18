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
    int T;
    cin >> T;
    while(T--){
        long long n, l, r;
        cin >> n >> l >> r;
        long long len = n * (n - 1) + 1;
        long long offset = (l - 1) % (2 * n - 2);
        long long start = (l - 1) / (2 * n - 2) + 1;
        vector<int> cycle;
        if(offset < n - 1){
            cycle = {start, start + offset + 1};
        }
        else{
            cycle = {start + (offset - (n - 1)), start};
        }
        while(cycle.size() < r - l + 1){
            if(cycle.back() == 1){
                if(cycle[cycle.size() - 2] == n){
                    cycle.push_back(cycle.back() + 1);
                }
                else{
                    cycle.push_back(cycle.back() - 1);
                }
            }
            else if(cycle.back() == n){
                cycle.push_back(cycle.back() - 1);
            }
            else{
                if(cycle[cycle.size() - 2] < cycle.back()){
                    cycle.push_back(cycle.back() + 1);
                }
                else{
                    cycle.push_back(cycle.back() - 1);
                }
            }
        }
        for(int i = 0; i < cycle.size(); i++){
            if(cycle[i] > n){
                cycle[i] -= n;
            }
        }
        for(int i = 0; i < cycle.size(); i++){
            cout << cycle[i] << (i == cycle.size() - 1 ? '\n' : ' ');
        }
    }
}