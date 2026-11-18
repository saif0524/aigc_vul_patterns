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

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<int> prefixB(n+1, 0), prefixW(n+1, 0);
    for(int i=1;i<=n;i++){
        prefixB[i] = prefixB[i-1] + (s[i-1] == 'B' || s[i-1] == 'X');
        prefixW[i] = prefixW[i-1] + (s[i-1] == 'W' || s[i-1] == 'X');
    }
    
    long long ans = 0;
    for(int i=0;i<=n-k;i++){
        if(prefixB[i+k] - prefixB[i] == k){
            for(int j=i+k;j<=n-k;j++){
                if(prefixW[j+k] - prefixW[j] == k){
                    long long x = 1;
                    for(int l=i;l<i+k;l++) if(s[l] == 'X') x = (x * 2) % MOD;
                    for(int l=j;l<j+k;l++) if(s[l] == 'X') x = (x * 2) % MOD;
                    ans = (ans + x) % MOD;
                }
            }
        }
    }
    cout << ans;
}