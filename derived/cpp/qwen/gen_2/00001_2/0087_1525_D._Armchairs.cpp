#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    
    vector<int> o, f;
    for(int i=0;i<n;i++){
        if(a[i] == 1) o.push_back(i);
        else f.push_back(i);
    }
    
    int ans = 0;
    for(int i=0;i<o.size();i++){
        ans += abs(o[i] - f[i]);
    }
    
    cout << ans;
}