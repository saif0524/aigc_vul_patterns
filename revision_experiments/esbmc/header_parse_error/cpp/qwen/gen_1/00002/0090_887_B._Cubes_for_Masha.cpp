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
    vector<vector<int>> cubes(n, vector<int>(6));
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            cin >> cubes[i][j];
        }
    }
    vector<int> digit_count(10, 0);
    for(auto &cube : cubes){
        for(int face : cube){
            digit_count[face]++;
        }
    }
    int x = 0;
    for(int i=1; ; i++){
        int num = i;
        bool can_form = true;
        vector<int> temp_count = digit_count;
        while(num > 0){
            int digit = num % 10;
            if(temp_count[digit] == 0){
                can_form = false;
                break;
            }
            temp_count[digit]--;
            num /= 10;
        }
        if(can_form){
            x = i;
        }
        else{
            break;
        }
    }
    cout << x;
}