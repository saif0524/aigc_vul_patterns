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
    int H, W;
    cin >> H >> W;
    vector<int> S(H*W);
    for(auto &x: S) cin >> x;
    
    set<int> nums;
    for(int i = 0; i < H*W; ++i){
        int x = S[i];
        if(x < 0 || x >= H*W || nums.count(x)){
            cout << "NO";
            return 0;
        }
        nums.insert(x);
    }
    
    vector<int> rank(H*W);
    for(int i = 0; i < H*W; ++i) rank[S[i]] = i;
    
    vector<int> rev(H*W);
    for(int i = 0; i < H; ++i){
        for(int j = 0, k = W-1; j < W; ++j, --k){
            rev[i*W + j] = i*W + k;
        }
    }
    
    auto check = [&](const vector<int>& perm){
        vector<int> ord(H*W);
        for(int i = 0; i < H*W; ++i) ord[perm[i]] = i;
        for(int s = 1; s <= H*W; s <<= 1){
            for(int L = 0; L < H*W; L += 2*s){
                int R = min(L + s, H*W);
                int E = min(L + 2*s, H*W);
                int p = L, q = R;
                while(p < R && q < E){
                    if(ord[p] < ord[q]) p++;
                    else q++;
                }
                if(p != R) return false;
            }
        }
        return true;
    };
    
    vector<int> S2;
    for(int i = 0; i < H; i += 2){
        for(int j = 0; j < W; ++j){
            S2.push_back(rev[S[i*W + j]]);
        }
        if(i + 1 < H){
            for(int j = 0; j < W; ++j){
                S2.push_back(S[(i+1)*W + j]);
            }
        }
    }
    
    vector<int> S3;
    for(int j = 0; j < W; ++j){
        for(int i = 0; i < H; i += 2){
            S3.push_back(rev[S[i*W + j]]);
        }
        if(j + 1 < W){
            for(int i = 0; i < H; i += 2){
                S3.push_back(S[i*W + (j+1)]);
            }
        }
    }
    
    if(check(rank) || check(rank) && check(S2) || check(rank) && check(S3)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}