#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> dp(n,0);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && a[i] > a[s.top()]){
            dp[i] = max(dp[i]+1, dp[s.top()]);
            s.pop();
        }
        s.push(i);
    }
    cout << *max_element(dp.begin(), dp.end());
}