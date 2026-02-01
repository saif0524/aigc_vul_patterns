#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = max(a.back() - 1, (int)1e6 - a[0]);
    for(int i=1;i<n;i++){
        ans = min(ans, max(a[i-1] - 1, (int)1e6 - a[i]));
    }
    cout << ans;
}