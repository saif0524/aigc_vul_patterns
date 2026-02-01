#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    map<int, vector<int>> pos_a;
    for(int i=0; i<n; ++i) pos_a[a[i]].push_back(i);
    vector<int> ans(n, n);
    for(int i=0; i<n; ++i){
        for(int x: pos_a[b[i]]){
            ans[i] = min(ans[i], abs(x - i));
            ans[(i-x+n)%n] = min(ans[(i-x+n)%n], abs(x - i));
        }
    }
    for(int x: ans) cout << x << '\n';
}