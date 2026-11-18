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
    ((void)0);
    ((void)0);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans = s;
        bool found = false;
        while(true){
            bool valid = true;
            int cnt[26] = {0};
            for(char c : ans) { cnt[c-'a']++; }
            for(int i=0; i<26; i++){
                if(cnt[i] % k != 0){
                    valid = false;
                    break;
                }
            }
            if(valid){
                found = true;
                break;
            }
            int pos = n-1;
            while(pos >= 0 && ans[pos] == 'z'){
                pos--;
            }
            if(pos < 0){
                break;
            }
            ans[pos]++;
            for(int i=pos+1; i<n; i++){
                ans[i] = 'a';
            }
        }
        if(found){
            cout << ans << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}