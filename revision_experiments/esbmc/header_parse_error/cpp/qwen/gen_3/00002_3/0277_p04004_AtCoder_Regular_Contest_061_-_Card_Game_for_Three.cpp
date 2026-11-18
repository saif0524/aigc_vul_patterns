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

typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll ans = 0;
    for(ll na = 0; na <= N; na++){
        for(ll nb = 0; nb <= M; nb++){
            for(ll nc = 0; nc <= K; nc++){
                ll total = na + nb + nc;
                if(total == 0) continue;
                ll cnt[3] = {na, nb, nc};
                ll cnta = 0, cntb = 0, cntc = 0;
                ll turn = 0;
                bool win[3] = {false, false, false};
                for(ll i = 0; i < total; i++){
                    if(cnt[turn] == 0){
                        win[turn] = true;
                        break;
                    }
                    cnt[turn]--;
                    if(turn == 0) cnta++;
                    if(turn == 1) cntb++;
                    if(turn == 2) cntc++;
                    turn = cnta - cntb >= 0 ? (cnta - cntc >= 0 ? 0 : 2) : (cntb - cntc >= 0 ? 1 : 2);
                }
                if(win[0]){
                    ll ways = 1;
                    ways = ways * (ll)pow(3, total - (na + nb + nc), MOD) % MOD;
                    ways = ways * (ll)pow(3, N - na, MOD) % MOD;
                    ways = ways * (ll)pow(3, M - nb, MOD) % MOD;
                    ways = ways * (ll)pow(3, K - nc, MOD) % MOD;
                    ans = (ans + ways) % MOD;
                }
            }
        }
    }
    cout << ans;
}