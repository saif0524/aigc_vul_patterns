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
    int N, Q;
    cin >> N >> Q;
    vector<optional<int>> diff(N+1);
    while(Q--){
        string type;
        cin >> type;
        if(type == "IN"){
            int A, B, C;
            cin >> A >> B >> C;
            if(!diff[A]) diff[A] = 0;
            if(!diff[B]) diff[B] = 0;
            diff[B] = diff[B].value() + C - diff[A].value();
        }
        else if(type == "COMPARE"){
            int A, B;
            cin >> A >> B;
            if(!diff[A] || !diff[B]){
                cout << "WARNING\n";
            }
            else{
                cout << diff[B].value() - diff[A].value() << "\n";
            }
        }
    }
}