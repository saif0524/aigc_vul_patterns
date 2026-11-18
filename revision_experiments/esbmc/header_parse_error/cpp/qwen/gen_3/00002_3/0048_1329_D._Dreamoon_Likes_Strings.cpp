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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<pair<int,int>> steps;
        for(int i=0; i<n; ){
            int j = i;
            while(j+1 < n && s[j] == s[j+1]) j++;
            if(j-i+1 >= 2){
                steps.push_back({i+1, j});
                i = j+1;
            } else {
                i++;
            }
        }
        for(int i=0; i<n;){
            int j = i;
            while(j+1 < n && s[j] == s[j+1]) j++;
            if(j-i+1 == 1){
                steps.push_back({i+1, i+1});
                i = j+1;
            } else {
                i = j+1;
            }
        }
        cout << steps.size() << "\n";
        for(auto p: steps){
            cout << p.first << " " << p.second << "\n";
        }
    }
}