#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int la, lb;
    cin >> la >> lb;
    vector<int> a(la), b(lb);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    int ans = 0;
    for(int shift=0; shift<la; shift++){
        int cnt = 0, j = 0;
        for(int i=0; i<la; i++){
            int cur = a[(i+shift)%la];
            while(j < lb && b[j] != cur) j++;
            if(j == lb) break;
            cnt++, j++;
        }
        ans = max(ans, cnt);
    }
    for(int shift=0; shift<lb; shift++){
        int cnt = 0, j = 0;
        for(int i=0; i<lb; i++){
            int cur = b[(i+shift)%lb];
            while(j < la && a[j] != cur) j++;
            if(j == la) break;
            cnt++, j++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}