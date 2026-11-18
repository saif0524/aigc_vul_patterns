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

const int MAX = 201;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, q;
        cin >> a >> b >> q;
        int lcm = (a * b) / gcd(a, b);
        int count[MAX][MAX];
        memset(count, 0, sizeof(count));
        for(int m = 0; m < lcm; m++){
            if((m % a % b) != (m % b % a)){
                for(int k = 0; k < lcm; k += a){
                    int mod = (m + k) % lcm;
                    count[k / a][mod]++;
                }
            }
        }
        while(q--){
            ll l, r;
            cin >> l >> r;
            ll first_group = (l - 1) / lcm + 1;
            ll last_group = r / lcm;
            ll first_mod = (l - 1) % lcm;
            ll last_mod = r % lcm;
            if(last_group >= first_group){
                ll ans = (last_group - first_group + 1) * lcm / a;
                ans -= (lcm / a - (first_mod / a + 1));
                ans -= (last_mod / a);
                for(int k = first_mod / a + 1; k <= last_mod / a; k++){
                    ans -= count[k][last_mod];
                }
                for(int k = 0; k <= first_mod / a; k++){
                    ans -= count[k][first_mod];
                }
                cout << ans << " ";
            }
            else{
                ll ans = 0;
                for(ll i = l; i <= r; i++){
                    if((i % a % b) != (i % b % a)){
                        ans++;
                    }
                }
                cout << ans << " ";
            }
        }
        cout << "\n";
    }
}