#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){
    string S, T;
    cin >> S >> T;
    int n = S.size();
    ll power = 1;
    ll sum = 0;
    ll ways = 1;
    bool constraint = true;
    
    for(int i=n-1; i>=0; i--){
        if(T[i] == '?'){
            if(constraint){
                sum = (sum + (ways * (S[i]-'0') * 9) % MOD) % MOD;
                ways = (ways * 10) % MOD;
            }
            else{
                sum = (sum + (ways * 45) % MOD) % MOD;
                ways = (ways * 10) % MOD;
            }
        }
        else{
            if(constraint){
                if(T[i] < S[i]){
                    constraint = false;
                }
                else if(T[i] > S[i]){
                    ways = 0;
                    break;
                }
            }
            sum = (sum + (ways * (T[i]-'0')) % MOD) % MOD;
            ways = (ways * 10) % MOD;
        }
    }
    cout << sum;
}