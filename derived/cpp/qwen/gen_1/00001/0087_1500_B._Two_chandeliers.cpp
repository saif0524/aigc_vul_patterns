#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    long long l = lcm(n, m);
    long long d = 0;
    for(long long i = 0; i < l; ++i){
        if(a[i % n] != b[i % m]) ++d;
    }
    long long cycles = (k + d - 1) / d;
    long long rem = k - (cycles - 1) * d;
    long long i = 0;
    while(rem > 0){
        if(a[i % n] != b[i % m]) --rem;
        ++i;
    }
    cout << (cycles - 1) * l + i;
}