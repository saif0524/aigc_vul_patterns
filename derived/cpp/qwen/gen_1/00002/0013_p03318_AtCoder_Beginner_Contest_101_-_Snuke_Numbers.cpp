#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll S(ll n) {
    ll sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll K;
    cin >> K;
    priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> pq;
    for(ll i=1;i<=9;i++){
        pq.push({(double)i/S(i), i});
    }
    set<ll> used;
    vector<ll> ans;
    while(ans.size() < K){
        auto p = pq.top();
        pq.pop();
        ll n = p.second;
        if(used.find(n) != used.end()) continue;
        used.insert(n);
        ans.push_back(n);
        for(ll i=0;i<=9;i++){
            ll next = n * 10 + i;
            if(next > 0){
                pq.push({(double)next/S(next), next});
            }
        }
    }
    for(ll a : ans){
        cout << a << "\n";
    }
}