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

typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){
    string S, T;
    cin >> S >> T;
    int n = S.size();
    ll power = 1;
    ll sum = 0;
    ll ways = 1;
    bool constraint = true;
    
    for(int i=n-1; i>=0; i--){
        if(T[i] == '?'){
            if(constraint){
                sum = (sum + (ways * (S[i]-'0') * 9) % MOD) % MOD;
                ways = (ways * 10) % MOD;
            }
            else{
                sum = (sum + (ways * 45) % MOD) % MOD;
                ways = (ways * 10) % MOD;
            }
        }
        else{
            if(constraint){
                if(T[i] < S[i]){
                    constraint = false;
                }
                else if(T[i] > S[i]){
                    ways = 0;
                    break;
                }
            }
            sum = (sum + (ways * (T[i]-'0')) % MOD) % MOD;
            ways = (ways * 10) % MOD;
        }
    }
    cout << sum;
}