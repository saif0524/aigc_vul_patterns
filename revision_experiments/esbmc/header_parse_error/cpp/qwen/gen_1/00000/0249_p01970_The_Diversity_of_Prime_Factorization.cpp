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

vector<ll> primes;

void sieve(int maxN) {
    vector<bool> isComposite(maxN + 1, false);
    for (int i = 2; i <= maxN; ++i) {
        if (!isComposite[i]) {
            primes.push_back(i);
            if (1LL * i * i <= maxN) {
                for (int j = i * i; j <= maxN; j += i) {
                    isComposite[j] = true;
                }
            }
        }
    }
}

ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

ll countWays(vector<pair<int, int>>& primeFactors) {
    ll totalWays = 1;
    for (auto& [p, e] : primeFactors) {
        totalWays = totalWays * (e + 1) % MOD;
    }
    return totalWays;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> q(N);
    for(auto& x: q) cin >> x;
    vector<bool> isPrime(1e6 + 1, true);
    isPrime[1] = false;
    for(int i=2;i*i<=1e6;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=1e6;j+=i){
                isPrime[j] = false;
            }
        }
    }
    int currentPrime = 1;
    vector<pair<int,int>> primeFactors;
    for(int i=0;i<N;i++){
        if(isPrime[q[i]]){
            int exp = 1;
            while(i+1 < N && q[i+1] == q[i]){
                exp++;
                i++;
            }
            primeFactors.push_back({q[i], exp});
        } else {
            cout << 0;
            return 0;
        }
    }
    cout << countWays(primeFactors);
}