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
    vector<pair<string, int>> files(n);
    for(auto &f : files){
        cin >> f.first >> f.second;
    }
    int e = 0;
    for(auto &f : files){
        if(f.second == 1) e++;
    }
    int regular = n, example = 1;
    vector<string> moves;
    for(auto &f : files){
        if(f.second == 1){
            if(stoi(f.first) != example){
                moves.push_back("move " + f.first + " " + to_string(example));
                f.first = to_string(example);
            }
            example++;
        }else{
            if(stoi(f.first) < e || stoi(f.first) > regular){
                moves.push_back("move " + f.first + " " + to_string(regular));
                f.first = to_string(regular);
            }
            regular--;
        }
    }
    cout << moves.size() << "\n";
    for(auto &m : moves){
        cout << m << "\n";
    }
}