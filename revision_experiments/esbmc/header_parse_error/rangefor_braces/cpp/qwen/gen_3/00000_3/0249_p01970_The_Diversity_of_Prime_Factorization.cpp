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
const int MOD = 1e9 + 7;

vector<int> spf;

void sieve(int n) {
    spf.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    int N;
    cin >> N;
    vector<int> q(N);
    for(auto &x: q) { cin >> x; }
    int max_q = *max_element(q.begin(), q.end());
    sieve(max_q);
    sort(q.begin(), q.end());
    vector<int> primes;
    vector<int> powers;
    for(int i = 0; i < N;){
        int p = q[i++];
        int cnt = 1;
        if(i < N && q[i] <= 10 && p*q[i] <= max_q && spf[p*q[i]] == p*q[i]){
            p *= q[i++];
            cnt = q[i++];
        }
        primes.push_back(p);
        powers.push_back(cnt);
    }
    if(primes.size() < N){
        cout << "0\n";
        return 0;
    }
    for(int i = 1; i < primes.size(); i++){
        if(primes[i-1] >= primes[i]){
            cout << "0\n";
            return 0;
        }
    }
    ll res = 1;
    for(auto &x: powers){
        res = (res * (x + 1)) % MOD;
    }
    cout << res << "\n";
}