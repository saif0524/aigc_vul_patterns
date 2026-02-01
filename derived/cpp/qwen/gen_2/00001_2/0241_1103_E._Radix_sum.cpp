#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull MOD = (1ULL << 58);

ull dp[100001][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    for(auto &i : x) cin >> i;
    for(int i=0;i<10;i++) dp[0][i]=0;
    for(int i=0;i<n;i++){
        int d=0;
        while(x[i]){
            dp[i+1][(d+x[i]%10)%10]+=1;
            dp[i+1][(d+x[i]%10)%10]%=MOD;
            d+=x[i]%10;
            d%=10;
            x[i]/=10;
        }
        for(int j=0;j<10;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[n][i] << (i==n-1?"\n":" ");
    }
}