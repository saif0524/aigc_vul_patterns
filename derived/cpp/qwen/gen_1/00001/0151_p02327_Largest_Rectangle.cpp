#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> mat(H, vector<int>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> mat[i][j];
        }
    }
    vector<int> dp(W, 0);
    int ans = 0;
    for(int i=0; i<H; i++){
        stack<pair<int, int>> st;
        for(int j=0; j<W; j++){
            if(mat[i][j] == 1) dp[j] = 0;
            else dp[j]++;
            while(!st.empty() && st.top().second >= dp[j]){
                int height = st.top().second;
                st.pop();
                int width = st.empty() ? j : j - st.top().first - 1;
                ans = max(ans, height * width);
            }
            st.push({j, dp[j]});
        }
        while(!st.empty()){
            int height = st.top().second;
            st.pop();
            int width = st.empty() ? W : W - st.top().first - 1;
            ans = max(ans, height * width);
        }
    }
    cout << ans;
}