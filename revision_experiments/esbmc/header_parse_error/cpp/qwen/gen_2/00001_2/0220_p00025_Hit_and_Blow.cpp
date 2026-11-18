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
    while(true){
        int A[4], B[4], hit = 0, blow = 0;
        if(!(cin >> A[0] >> A[1] >> A[2] >> A[3])) break;
        cin >> B[0] >> B[1] >> B[2] >> B[3];
        for(int i = 0; i < 4; i++){
            if(A[i] == B[i]) hit++;
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i != j && A[i] == B[j]) blow++;
            }
        }
        cout << hit << " " << blow << endl;
    }
}