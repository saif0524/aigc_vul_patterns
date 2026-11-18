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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<pair<int,int>> res;
        for(int i=1;i<n;){
            int j = i;
            while(j < n && s[j] == s[j-1]) j++;
            if(j-i > 0){
                if((j-i) % 2 == 1){
                    res.push_back({i,i});
                    i++;
                }
                while(i < j){
                    res.push_back({i,i+1});
                    i += 2;
                }
            }
            else i++;
        }
        if(n % 2 == 1) res.push_back({n,n});
        cout << res.size() << "\n";
        for(auto [l,r] : res){
            cout << l << " " << r << "\n";
        }
    }
}