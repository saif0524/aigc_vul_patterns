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
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int a = 6;
        while(true){
            int cnt = 0;
            for(int i=1;i*i<=a;i++){
                if(a%i==0){
                    if(i*i==a) cnt++;
                    else cnt+=2;
                }
            }
            if(cnt>=4){
                bool valid = true;
                for(int i=1;i<=a/2;i++){
                    if(a%i==0){
                        if((a/(a/i)-i)<d){
                            valid = false;
                            break;
                        }
                    }
                }
                if(valid){
                    cout << a << "\n";
                    break;
                }
            }
            a++;
        }
    }
}