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

const int MAXN = 400000+ 5;
int cnt[MAXN], mex = 0;

void update_mex() {
    while (cnt[mex]) mex++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin >> q >> x;
    for(int i=0; i<q; i++){
        int y;
        cin >> y;
        if(y >= MAXN){
            // No need to consider y if it's too large
            update_mex();
            cout << mex << "\n";
            continue;
        }
        cnt[y]++;
        while(cnt[mex]){
            mex++;
        }
        // Try to fill gaps using x
        for(int j=0; j<mex; j++){
            if(!cnt[j]){
                int need = j - y;
                if(need % x ==0 && need / x >= 0 && cnt[y + need / x]){
                    cnt[y + need / x]--;
                    cnt[j]++;
                }
            }
        }
        update_mex();
        cout << mex << "\n";
    }
}