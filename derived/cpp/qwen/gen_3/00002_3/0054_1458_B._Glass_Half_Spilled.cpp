#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> glasses(n);
    for(auto &g: glasses) cin >> g.first >> g.second;
    sort(glasses.begin(), glasses.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return (a.first - a.second) > (b.first - b.second);
    });
    vector<double> dp(n+1, 0);
    for(int i=0; i<n; i++){
        for(int j=i; j>=1; j--){
            double transferable = min(glasses[i].second - dp[j], (dp[j-1] - dp[j])*2);
            dp[j] += transferable / 2;
        }
        dp[i+1] = dp[i] + glasses[i].second;
    }
    for(int i=1; i<=n; i++) cout << setprecision(10) << fixed << min(dp[i], (double)accumulate(glasses.begin(), glasses.end(), 0, [](double sum, const pair<int,int>& g){return sum + g.second;})) << " ";
}