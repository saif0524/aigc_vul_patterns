#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for(auto &s : a) cin >> s;
    for(auto &s : b) cin >> s;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < max(a[i].size(), b[i].size()); ++j){
            if(j >= a[i].size() || j >= b[i].size() || a[i][j] != b[i][j]){
                ans++;
            }
        }
    }
    cout << ans;
}