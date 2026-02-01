#include <bits/stdc++.h>
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> q(N);
    for(auto &x: q) cin >> x;
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