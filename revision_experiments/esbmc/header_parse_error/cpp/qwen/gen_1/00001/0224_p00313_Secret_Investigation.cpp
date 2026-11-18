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
    int N;
    cin >> N;
    
    set<int> A, B, C;
    int X, Y, Z;
    
    cin >> X;
    for(int i=0;i<X;i++){
        int a;
        cin >> a;
        A.insert(a);
    }
    
    cin >> Y;
    for(int i=0;i<Y;i++){
        int b;
        cin >> b;
        B.insert(b);
    }
    
    cin >> Z;
    for(int i=0;i<Z;i++){
        int c;
        cin >> c;
        C.insert(c);
    }
    
    set<int> result;
    
    for(int c: C){
        if(A.find(c) == A.end()){
            result.insert(c);
        }
    }
    
    for(int c: C){
        if(B.find(c) != B.end()){
            result.insert(c);
        }
    }
    
    cout << result.size();
}