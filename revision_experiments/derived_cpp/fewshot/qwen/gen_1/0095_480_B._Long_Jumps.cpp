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
    bool can_x = false, can_y = false;
    for(int i=0; i<n; i++){
        if(s.count(a[i]+x)) can_x = true;
        if(s.count(a[i]+y)) can_y = true;
    }
    if(can_x && can_y){
        cout << 0 << "\n";
        return 0;
    }
    vector<long long> ans;
    if(!can_x){
        ans.push_back(x);
        s.insert(x);
    }
    if(!can_y){
        ans.push_back(y);
        s.insert(y);
    }
    for(int i=0; i<n; i++){
        if(!can_x && s.count(a[i]+x)){
            can_x = true;
        }
        if(!can_y && s.count(a[i]+y)){
            can_y = true;
        }
    }
    if(can_x && can_y){
        cout << 1 << "\n";
        cout << ans[0] << "\n";
        return 0;
    }
    cout <<2<< "\n";
    for(auto &ai : ans){
        cout << ai << " ";
    }
    cout << "\n";
}