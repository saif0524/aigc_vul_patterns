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

const int MAXN = 300005;
const int MAXB = 20;

int n, q;
int a[MAXN];
vector<int> idx[MAXB];
int bit[MAXN][MAXB];

inline void update(int idx, int bit, int val) {
    for (; idx < MAXN; idx += idx & -idx) {
        bit[idx] = max(bit[idx], val);
    }
}

inline int query(int idx, int bit) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) {
        res = max(res, bit[idx]);
    }
    return res;
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int b=0;b<MAXB;b++){
        for(int i=1;i<=n;i++){
            if(a[i] & (1<<b)){
                idx[b].push_back(i);
            }
        }
        for(int i=0;i<idx[b].size();i++){
            int pos = idx[b][i];
            update(pos, bit[b], pos);
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        bool reachable = false;
        for(int b=0;b<MAXB;b++){
            if((a[x] & (1<<b)) && (a[y] & (1<<b))){
                int res = query(y-1, bit[b]);
                if(res >= x){
                    reachable = true;
                    break;
                }
            }
        }
        if(reachable) cout << "Shi\n";
        else cout << "Fou\n";
    }
}