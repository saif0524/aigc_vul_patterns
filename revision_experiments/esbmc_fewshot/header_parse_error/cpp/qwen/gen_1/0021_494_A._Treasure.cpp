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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    int open = 0, close =0, hash = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') open++;
        else if(s[i]==')') close++;
        else hash++;
    }
    if(open!=close+hash){
        cout << -1;
        return 0;
    }
    open = 0, close = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') open++;
        else if(s[i]==')'){
            close++;
            if(close>open){
                cout << -1;
                return 0;
            }
        }
        else{
            int need = open-close+1;
            if(need<=0){
                cout << -1;
                return 0;
            }
            ans.push_back(need);
            close+=need;
        }
    }
    if(open!=close){
        cout << -1;
        return 0;
    }
    for(auto x:ans){
        cout << x << "\n";
    }
}