#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < n; ++i){
        string x = a[i], y = b[i];
        if(x.size() != y.size()){
            ans += abs((int)x.size() - (int)y.size());
            x.resize(y.size(), 'M');
        }
        for(int j = 0; j < x.size(); ++j) if(x[j] != y[j]) ++ans;
    }
    cout << ans;
}