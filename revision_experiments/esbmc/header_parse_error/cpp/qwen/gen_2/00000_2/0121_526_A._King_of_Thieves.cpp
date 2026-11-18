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
    cin >> n;
    string s;
    cin >> s;
    vector<int> platforms;
    for(int i=0;i<n;i++){
        if(s[i] == '*'){
            platforms.push_back(i);
        }
    }
    int m = platforms.size();
    for(int i=0;i<m-4;i++){
        for(int j=i+1;j<m-3;j++){
            int diff = platforms[j] - platforms[i];
            if(platforms[j+1] - platforms[j] == diff && platforms[j+2] - platforms[j+1] == diff && platforms[j+3] - platforms[j+2] == diff){
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
}