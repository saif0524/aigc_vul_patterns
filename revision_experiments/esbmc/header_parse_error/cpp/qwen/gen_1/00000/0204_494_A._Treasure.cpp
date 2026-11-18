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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    int open = 0, close = 0, hash = 0;
    for(char c : s){
        if(c == '(') open++;
        else if(c == ')') close++;
        else hash++;
    }
    if(open != close + hash){
        cout << -1;
        return 0;
    }
    int curr_open = 0;
    bool valid = true;
    for(char c : s){
        if(c == '('){
            curr_open++;
        }
        else if(c == ')'){
            curr_open--;
            if(curr_open < 0){
                valid = false;
                break;
            }
        }
        else{
            int need = open - curr_open - (hash-1);
            if(need <= 0 || curr_open + need > open){
                valid = false;
                break;
            }
            ans.push_back(need);
            curr_open += need;
            hash--;
        }
    }
    if(!valid || curr_open != open){
        cout << -1;
    }
    else{
        for(int x : ans){
            cout << x << "\n";
        }
    }
}