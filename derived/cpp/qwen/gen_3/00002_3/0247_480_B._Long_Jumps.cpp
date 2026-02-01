#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    long long l;
    cin >> n >> l >> x >> y;
    vector<long long> a(n);
    for(auto &ai : a) cin >> ai;
    set<long long> s(a.begin(), a.end());
    int ans = 0;
    vector<long long> to_add;
    if(s.find(x) == s.end()){
        ++ans;
        to_add.push_back(x);
    }
    if(s.find(y) == s.end()){
        ++ans;
        to_add.push_back(y);
    }
    cout << ans << "\n";
    for(auto &ai : to_add) cout << ai << " ";
    cout << "\n";
}