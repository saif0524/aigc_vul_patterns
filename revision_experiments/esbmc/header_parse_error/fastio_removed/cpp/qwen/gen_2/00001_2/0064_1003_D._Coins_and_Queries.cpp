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
    int n, q;
    cin >> n >> q;
    vector<int> cnt(31, 0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        for(int j=0;j<=30;j++){
            if(x == (1 << j)){
                cnt[j]++;
                break;
            }
        }
    }
    while(q--){
        int b;
        cin >> b;
        int ans = 0;
        for(int i=0;i<=30;i++){
            if(b & (1 << i)){
                if(cnt[i] > 0){
                    cnt[i]--;
                }
                else{
                    bool found = false;
                    for(int j=i+1;j<=30;j++){
                        if(cnt[j] > 0){
                            cnt[j]--;
                            for(int k=i;k<j;k++){
                                cnt[k]++;
                            }
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        ans = -1;
                        break;
                    }
                }
                ans++;
            }
        }
        cout << ans << "\n";
    }
}