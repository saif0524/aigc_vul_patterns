#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tags(n), scores(n);
        for(int &x: tags) cin >> x;
        for(int &x: scores) cin >> x;
        vector<long long> dp(1<<13, -1LL);
        dp[0] = 0;
        for(int i=0; i<n; ++i){
            for(int mask=0; mask<(1<<13); ++mask){
                if(dp[mask] == -1) continue;
                for(int j=0; j<n; ++j){
                    if(i == j) continue;
                    if(tags[i] == tags[j]) continue;
                    int iq = abs((1<<i) - (1<<j));
                    if(iq <= mask) continue;
                    int new_mask = mask | (1<<iq);
                    dp[new_mask] = max(dp[new_mask], dp[mask] + abs(scores[i] - scores[j]));
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
}