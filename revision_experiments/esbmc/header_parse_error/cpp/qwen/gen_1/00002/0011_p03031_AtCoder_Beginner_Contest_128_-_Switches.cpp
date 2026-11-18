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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> bulbs(M);
    vector<int> p(M);
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        bulbs[i] = vector<int>(k);
        for(int j = 0; j < k; j++){
            cin >> bulbs[i][j];
            bulbs[i][j]--;
        }
    }
    for(int i = 0; i < M; i++){
        cin >> p[i];
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << N); mask++){
        bool valid = true;
        for(int i = 0; i < M; i++){
            int cnt = 0;
            for(int j = 0; j < bulbs[i].size(); j++){
                if(mask & (1 << bulbs[i][j])){
                    cnt++;
                }
            }
            if(cnt % 2 != p[i]){
                valid = false;
                break;
            }
        }
        if(valid){
            ans++;
        }
    }
    cout << ans;
}