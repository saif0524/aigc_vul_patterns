#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    map<ll, int> factors;
    for(const auto &x : a){
        for(ll i = 2; i * i <= x; i++){
            while(x % i == 0){
                factors[i]++;
                x /= i;
            }
        }
        if(x > 1) factors[x]++;
    }
    int half = (n + 1) / 2;
    ll result = 1;
    for(const auto &[p, cnt] : factors){
        if(cnt >= half){
            int k = cnt / half;
            result *= pow(p, k);
        }
    }
    cout << result;
}