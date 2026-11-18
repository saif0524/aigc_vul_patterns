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
    int n, k;
    while(cin >> n >> k){
        if(n==0 && k==0) break;
        vector<int> cards(n);
        for(auto &x: cards) cin >> x;
        long long best = 0;
        long long cur = 1;
        for(int i = 0; i < k; ++i){
            cur *= cards[i];
        }
        best = cur;
        for(int i = k; i < n; ++i){
            cur /= cards[i-k];
            cur *= cards[i];
            best = max(best, cur);
        }
        long long ans = -1;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                swap(cards[i], cards[j]);
                cur = 1;
                for(int l = 0; l < k; ++l){
                    cur *= cards[l];
                }
                long long local_best = cur;
                for(int l = k; l < n; ++l){
                    cur /= cards[l-k];
                    cur *= cards[l];
                    local_best = max(local_best, cur);
                }
                if(local_best > best){
                    ans = max(ans, local_best - best);
                }
                swap(cards[i], cards[j]);
            }
        }
        if(ans == -1){
            cout << "NO GAME\n";
        }
        else{
            cout << ans << "\n";
        }
    }
}