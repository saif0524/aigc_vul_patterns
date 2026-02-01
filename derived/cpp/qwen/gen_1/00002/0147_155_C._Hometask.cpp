#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<pair<char, char>> forbidden(k);
    for(auto &it: forbidden){
        cin >> it.first >> it.second;
    }
    vector<int> dp(26, 0);
    for(auto c: s){
        int max_val = 0;
        for(auto &[a, b]: forbidden){
            if(a==c || b==c){
                continue;
            }
            max_val = max(max_val, dp[a-'a']);
            max_val = max(max_val, dp[b-'a']);
        }
        if(dp[c-'a'] < max_val + 1){
            dp[c-'a'] = max_val + 1;
        }
    }
    int max_val = 0;
    for(auto &it: dp){
        max_val = max(max_val, it);
    }
    cout << (int)s.length() - max_val;
}