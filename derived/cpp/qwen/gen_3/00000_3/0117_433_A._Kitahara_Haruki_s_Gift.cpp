#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    for(int i=0; i<n; ++i){
        cin >> w[i];
        sum += w[i];
    }
    if(sum % 2 != 0){
        cout << "NO";
        return 0;
    }
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for(int i=0; i<n; ++i){
        for(int j=target; j>=w[i]; --j){
            dp[j] = dp[j] || dp[j - w[i]];
        }
    }
    cout << (dp[target] ? "YES" : "NO");
}