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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(101, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        int mexA = 0;
        int mexB = 0;
        for(int i = 0; i <= 100; i++){
            if(cnt[i] == 0){
                mexA = i;
                break;
            }
        }
        for(int i = 0; i <= 100; i++){
            if(cnt[i] <= 1){
                mexB = i;
                break;
            }
        }
        int ans = mexA + mexB;
        for(int i = 0; i <= 100; i++){
            if(cnt[i] > 1){
                int new_mexA = mexA;
                int new_mexB = mexB;
                if(mexA == i){
                    new_mexA++;
                    while(new_mexA <= 100 && cnt[new_mexA] > 0){
                        new_mexA++;
                    }
                }
                if(mexB == i){
                    new_mexB++;
                    while(new_mexB <= 100 && cnt[new_mexB] > 0){
                        new_mexB++;
                    }
                }
                ans = max(ans, new_mexA + new_mexB);
            }
        }
        cout << ans << "\n";
    }
}