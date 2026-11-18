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
    int n;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n/4));
    for(int i=0;i<n;i++){
        for(int j=0;j<n/4;j++){
            cin >> mat[i][j];
        }
    }
    auto check = [&](int x){
        for(int i=0;i<n;i+=x){
            for(int j=0;j<n;j+=x){
                char val = mat[i][j/4];
                for(int ii=i;ii<i+x;ii++){
                    for(int jj=j;jj<j+x;jj++){
                        if(((val >> (3- (jj%4))) & 1) != ((mat[ii][jj/4] >> (3- (jj%4))) & 1)){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    };
    int ans = 1;
    for(int x=2;x<=n;x*=2){
        if(check(x)){
            ans = x;
        }
    }
    cout << ans;
}