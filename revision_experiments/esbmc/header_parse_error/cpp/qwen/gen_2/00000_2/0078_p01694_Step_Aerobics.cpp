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
        int n;
        cin >> n;
        if(n == 0) break;
        vector<string> moves(n);
        for(auto &m : moves) cin >> m;
        int count = 0;
        bool onFloor = true;
        for(int i=0; i<n; i++){
            if(onFloor){
                if(moves[i].substr(0, 1) == "l" || moves[i].substr(0, 1) == "r"){
                    if((i+1 < n && moves[i+1].substr(0, 1) != moves[i].substr(0, 1))){
                        i++;
                        if(i < n){
                            count++;
                            onFloor = false;
                        }
                    }
                }
            } else {
                if(moves[i].substr(1, 1) == "d" && (moves[i].substr(0, 1) == "l" || moves[i].substr(0, 1) == "r")){
                    if((i+1 < n && moves[i+1].substr(0, 1) != moves[i].substr(0, 1))){
                        i++;
                        if(i < n){
                            count++;
                            onFloor = true;
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
}