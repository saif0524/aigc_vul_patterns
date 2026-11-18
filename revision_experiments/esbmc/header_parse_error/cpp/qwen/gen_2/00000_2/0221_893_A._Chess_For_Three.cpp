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
    int winner[n];
    for(int i=0;i<n;i++){
        cin >> winner[i];
    }
    int spec = 3;
    if(winner[0]==3){
        spec = 1;
    }
    for(int i=0;i<n;i++){
        if(winner[i]==spec){
            cout << "NO";
            return 0;
        }
        int next_spec;
        if(winner[i]==1){
            next_spec = (spec==2)?3:2;
        }
        if(winner[i]==2){
            next_spec = (spec==1)?3:1;
        }
        if(winner[i]==3){
            next_spec = (spec==1)?2:1;
        }
        spec = next_spec;
    }
    cout << "YES";
    return 0;
}