#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> pos(n+1);
    for(int i=0;i<n;i++) pos[a[i]]=i;
    vector<int> dp(n,1);
    int mx = 1;
    for(int i=1;i<=n;i++){
        if(pos[i] > 0 && pos[i-1] < pos[i]){
            dp[pos[i]] = max(dp[pos[i]], dp[pos[i-1]] + 1);
        }
        if(pos[i] < n-1 && pos[i+1] > pos[i]){
            dp[pos[i]] = max(dp[pos[i]], dp[pos[i+1]] + 1);
        }
        mx = max(mx, dp[pos[i]]);
    }
    cout << n - mx;
}