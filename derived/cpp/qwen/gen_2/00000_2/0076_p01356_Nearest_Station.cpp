#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main(){
    ll n, m, a, b, p, q;
    cin >> n >> m >> a >> b >> p >> q;
    
    unordered_set<ll> reachable;
    
    for(ll i=0; i<n; i++){
        ll station = p*a*i + q*b*i;
        if(station <= m){
            reachable.insert(station);
        }
    }
    
    ll min_steps = m;
    for(const auto& s : reachable){
        if(m % (m - s) == 0){
            min_steps = min(min_steps, m - s);
        }
    }
    
    ll count = 0;
    for(const auto& s : reachable){
        if(m - s == min_steps){
            count++;
        }
    }
    
    cout << count;
    
    return 0;
}