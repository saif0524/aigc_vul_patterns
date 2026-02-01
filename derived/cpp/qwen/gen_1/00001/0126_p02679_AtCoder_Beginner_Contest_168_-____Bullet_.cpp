#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<ll, ll>> sardines(N);
    for(auto &s : sardines) cin >> s.first >> s.second;
    
    map<pair<ll, ll>, int> ratioCount;
    for(const auto& s : sardines){
        ll a = s.first, b = s.second;
        if(a == 0 && b == 0) continue;
        ll g = __gcd(a, b);
        if(a < 0 || (a == 0 && b < 0)){
            a = -a;
            b = -b;
        }
        ratioCount[{a / g, b / g}]++;
    }
    
    ll zeroCount = count(sardines.begin(), sardines.end(), make_pair(0LL, 0LL));
    ll ans = 1;
    for(const auto& [_, count] : ratioCount){
        ans = (ans * (1 + (1LL << count))) % MOD;
    }
    ans = (ans + zeroCount) % MOD;
    
    cout << ans;
}