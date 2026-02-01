#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> subsets(k);
    vector<vector<int>> pos(n+1);
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        for(int j=0;j<c;j++){
            int x;
            cin >> x;
            subsets[i].push_back(x);
            pos[x].push_back(i);
        }
    }
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    vector<int> switches(n+1);
    vector<int> last(k,-1);
    for(int i=1;i<=n;i++){
        int state = s[i-1]-'0';
        if(pos[i].size()==2){
            for(int id : pos[i]){
                int j = last[id];
                if(j!=-1){
                    dp[i] = min(dp[i],dp[j]^1);
                    switches[i] = switches[j]^1;
                }
            }
        }
        dp[i] = min(dp[i],dp[i-1]);
        switches[i] = switches[i-1];
        for(int id : pos[i]){
            last[id] = i;
        }
        int need = 1^state;
        if(switches[i]==need){
            dp[i] = min(dp[i],dp[i-1]+1);
        }
        if(pos[i].size()==1){
            int id = pos[i][0];
            int j = last[id];
            if(j!=-1){
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dp[i] << "\n";
    }
}