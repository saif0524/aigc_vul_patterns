#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    map<char, char> forbidden;
    for(int i=0; i<k; i++){
        char a, b;
        cin >> a >> b;
        forbidden[a] = b;
        forbidden[b] = a;
    }
    int n = s.size();
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1];
        if(forbidden.count(s[i-1])){
            char other = forbidden[s[i-1]];
            if(i > 1 && s[i-2] == other){
                dp[i] = min(dp[i], dp[i-2] + 1);
            }else{
                dp[i] = min(dp[i], dp[i-1] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
}