#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int ans = max(a[0]-1, 1000000-a[n-1]);
    for(int i=1;i<n;i++) ans = max(ans, (a[i]-a[i-1])/2);
    cout << ans;
}