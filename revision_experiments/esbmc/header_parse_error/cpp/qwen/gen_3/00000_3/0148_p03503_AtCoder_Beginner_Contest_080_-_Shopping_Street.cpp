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
    int N;
    cin >> N;
    vector<vector<vector<int>>> F(N, vector<vector<int>>(5, vector<int>(2)));
    vector<vector<int>> P(N, vector<int>(11));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<2;k++){
                cin >> F[i][j][k];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<11;j++){
            cin >> P[i][j];
        }
    }
    
    int max_profit = INT_MIN;
    for(int mask=1;mask<(1<<10);mask++){
        int profit = 0;
        for(int i=0;i<N;i++){
            int cnt = 0;
            for(int j=0;j<5;j++){
                for(int k=0;k<2;k++){
                    if((mask & (1<<(j*2+k))) && F[i][j][k]){
                        cnt++;
                    }
                }
            }
            profit += P[i][cnt];
        }
        max_profit = max(max_profit, profit);
    }
    
    cout << max_profit;
}