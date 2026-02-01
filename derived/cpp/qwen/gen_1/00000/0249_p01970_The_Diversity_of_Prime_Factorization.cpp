#include <bits/stdc++.h>
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