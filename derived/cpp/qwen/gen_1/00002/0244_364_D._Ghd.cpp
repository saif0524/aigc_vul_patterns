#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll, int> divisors_count;
    for(int i = 0; i < n; i++){
        ll x = a[i];
        for(ll d = 2; d * d <= x; d++){
            while(x % d == 0){
                divisors_count[d]++;
                x /= d;
            }
        }
        if(x > 1) divisors_count[x]++;
    }
    ll ghd = 0, max_count = 0;
    for(auto& p : divisors_count){
        if(p.second >= (n + 1) / 2){
            if(p.second > max_count){
                max_count = p.second;
                ghd = p.first;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(divisors_count.count(i) && divisors_count[i] == max_count){
            ghd = min(ghd, (ll)i);
        }
    }
    cout << ghd;
}