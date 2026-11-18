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
    int n;
    string s;
    cin >> n >> s;
    vector<string> result;
    int count0 = 0, count1 = 0;
    string current = "";
    for(char c: s){
        current += c;
        if(c == '0') count0++;
        else count1++;
        if(count0 != 0 && count1 != 0 && count0 == count1){
            result.push_back(current);
            current = "";
            count0 = 0;
            count1 = 0;
        }
    }
    if(!current.empty()) result.push_back(current);
    cout << result.size() << endl;
    for(int i=0;i<result.size();i++){
        cout << result[i];
        if(i < result.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}