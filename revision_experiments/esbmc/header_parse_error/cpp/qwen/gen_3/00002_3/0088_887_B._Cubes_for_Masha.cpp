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
    vector<unordered_map<int, int>> faces(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            int f;
            cin >> f;
            faces[i][f]++;
        }
    }
    int count[10] = {0};
    for(int d=0;d<10;d++){
        for(int i=0;i<n;i++){
            count[d] += faces[i][d];
        }
    }
    int x = 0;
    for(int num=1;;num++){
        int n = num;
        bool possible = true;
        while(n > 0){
            int digit = n % 10;
            if(digit == 6 || digit == 9){
                if(count[6] + count[9] == 0){
                    possible = false;
                    break;
                }
                if(digit == 6){
                    if(count[6] > 0){
                        count[6]--;
                    } else {
                        count[9]--;
                    }
                } else {
                    if(count[9] > 0){
                        count[9]--;
                    } else {
                        count[6]--;
                    }
                }
            } else {
                if(count[digit] == 0){
                    possible = false;
                    break;
                }
                count[digit]--;
            }
            n /= 10;
        }
        if(!possible){
            x = num - 1;
            break;
        }
        for(int d=0;d<10;d++){
            count[d] += faces[num / (int)pow(10, int(log10(num)) + 1) % 10][d];
        }
    }
    cout << x;
}