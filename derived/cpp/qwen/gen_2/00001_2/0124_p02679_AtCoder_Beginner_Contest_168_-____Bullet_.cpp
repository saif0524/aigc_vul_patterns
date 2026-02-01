#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

map<pair<ll, ll>, int> slopes;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        ll A, B;
        cin >> A >> B;
        if(A==0){
            if(B==0) continue;
            slopes[{0,1}]++;
        }
        else{
            ll g = __gcd(A, B);
            A /= g;
            B /= g;
            ll sign = (A<0 || (A==0 && B<0))?-1:1;
            A *= sign;
            B *= sign;
            slopes[{A,B}]++;
        }
    }
    long long ans = 1;
    for(auto& [_, cnt] : slopes){
        ans = (ans * (1 + (1LL << cnt))) % MOD;
    }
    cout << (ans-1+MOD)%MOD << "\n";
    return 0;
}