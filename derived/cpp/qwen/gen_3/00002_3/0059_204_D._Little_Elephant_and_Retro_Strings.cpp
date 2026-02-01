#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<int> prefixB(n+1, 0), prefixW(n+1, 0);
    for(int i=1;i<=n;i++){
        prefixB[i] = prefixB[i-1] + (s[i-1] == 'B' || s[i-1] == 'X');
        prefixW[i] = prefixW[i-1] + (s[i-1] == 'W' || s[i-1] == 'X');
    }
    
    long long ans = 0;
    for(int i=0;i<=n-k;i++){
        if(prefixB[i+k] - prefixB[i] == k){
            for(int j=i+k;j<=n-k;j++){
                if(prefixW[j+k] - prefixW[j] == k){
                    long long x = 1;
                    for(int l=i;l<i+k;l++) if(s[l] == 'X') x = (x * 2) % MOD;
                    for(int l=j;l<j+k;l++) if(s[l] == 'X') x = (x * 2) % MOD;
                    ans = (ans + x) % MOD;
                }
            }
        }
    }
    cout << ans;
}