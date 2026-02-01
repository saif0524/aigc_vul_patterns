#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    return true;
}

vector<int> factorize(int num) {
    vector<int> factors;
    int cnt = 0;
    while (num % 2 == 0) {
        num /= 2;
        cnt++;
    }
    if (cnt > 0) factors.push_back(cnt);
    for (int i = 3; i * i <= num; i += 2) {
        cnt = 0;
        while (num % i == 0) {
            num /= i;
            cnt++;
        }
        if (cnt > 0) factors.push_back(cnt);
    }
    if (num > 2) factors.push_back(1);
    return factors;
}

int power_mod(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp % 2) result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> q(n);
    for(int &x: q) cin >> x;
    vector<int> primes;
    for(int &x: q){
        if(!is_prime(x)){
            cout << 0;
            return 0;
        }
        primes.push_back(x);
    }
    sort(primes.begin(), primes.end());
    unique(primes.begin(), primes.end());
    if(primes.size() != (int)unique(primes.begin(), primes.end()) - primes.begin()){
        cout << 0;
        return 0;
    }
    vector<int> exponents;
    for(int i=0;i<n;){
        if(q[i]==primes[exponents.size()]){
            exponents.push_back(1);
            i++;
        } else{
            exponents.push_back(q[i+1]);
            i+=2;
        }
    }
    int result=1;
    for(int exp: exponents){
        result = (1LL*result*power_mod(exp+1,MOD-2))%MOD;
    }
    cout << result;
}