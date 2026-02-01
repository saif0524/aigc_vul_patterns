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
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        subsets[i] = vector<int>(c);
        for(int j=0;j<c;j++){
            cin >> subsets[i][j];
            subsets[i][j]--;
        }
    }
    vector<int> oncnt(n, 0);
    for(int i=0;i<k;i++){
        for(int x : subsets[i]){
            oncnt[x]++;
        }
    }
    vector<vector<int>> indices(n);
    for(int i=0;i<k;i++){
        for(int x : subsets[i]){
            indices[x].push_back(i);
        }
    }
    vector<int> dp(k, 0);
    vector<int> ans(n, 0);
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            ans[i] = 0;
            continue;
        }
        int req = 1;
        for(int ind : indices[i]){
            if(dp[ind] == 1){
                req--;
            }
            dp[ind] ^= 1;
        }
        ans[i] = req;
    }
    for(int i=1;i<n;i++){
        ans[i] += ans[i-1];
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << "\n";
    }
}