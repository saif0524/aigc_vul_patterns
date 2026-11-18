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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    for(int i=0; i<m; ++i){
        cin >> c[i];
    }
    vector<int> pos(m);
    int sum = 0;
    for(int i=0; i<m; ++i){
        pos[i] = sum + 1;
        sum += c[i];
    }
    while(true){
        bool found = true;
        for(int i=1; i<m; ++i){
            if(pos[i] - pos[i-1] <= d){
                found = false;
                break;
            }
        }
        if(found) break;
        for(int i=m-1; i>0; --i){
            if(pos[i] - pos[i-1] <= d){
                pos[i] +=1;
            }
        }
        if(pos[0] + d < pos[1]){
            pos[0] += 1;
        }
    }
    vector<int> ans(n+1,0);
    for(int i=0; i<m; ++i){
        for(int j=0; j<c[i]; ++j){
            ans[pos[i]+j-1] = i+1;
        }
    }
    for(int i=1; i<=n; ++i){
        if(ans[i] == 0 && i + d >= n + 1){
            ans[i] = m;
            break;
        }
    }
    bool can_reach = false;
    for(int i=1; i<=n; ++i){
        if(ans[i-1] != 0){
            if(i + d >= n + 1){
                can_reach = true;
            }
            for(int j=i+1; j<=n && j<=i+d; ++j){
                if(ans[j-1] != 0){
                    i = j-1;
                    break;
                }
            }
        }
    }
    if(can_reach){
        cout << "YES\n";
        for(int i=1; i<=n; ++i){
            cout << ans[i-1] << (i==n?"":" ");
        }
    }else{
        cout << "NO";
    }
}