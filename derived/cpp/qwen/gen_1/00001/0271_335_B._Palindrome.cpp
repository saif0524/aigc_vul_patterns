#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(26, 0));
    for(int i=n-1;i>=0;i--){
        dp[i] = dp[i+1];
        dp[i][s[i]-'a']++;
    }
    string ans;
    for(int i=0;i<n&&ans.size()<100;){
        int ch = -1;
        for(int j=0;j<26;j++){
            if(dp[i][j] > 1){
                ch = j;
                break;
            }
        }
        if(ch != -1){
            ans += char(ch+'a');
            i++;
            while(s[i] != char(ch+'a')) i++;
            i++;
        }
        else{
            for(int j=0;j<26;j++){
                if(dp[i][j] > 0){
                    ch = j;
                    break;
                }
            }
            if(ch != -1){
                ans += char(ch+'a');
                i++;
            }
            else break;
        }
    }
    int len = ans.size();
    if(len >= 100) cout << ans.substr(0,100);
    else{
        string rev = ans;
        reverse(rev.begin(), rev.end());
        ans += rev.substr(len-1);
        cout << ans;
    }
}