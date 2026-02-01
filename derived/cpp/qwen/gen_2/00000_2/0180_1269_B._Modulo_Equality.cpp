#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = m;
    for(int i = 0; i < n; i++){
        int x = (b[i] - a[0] + m) % m;
        bool ok = true;
        for(int j = 0; j < n; j++){
            if((a[j] + x) % m != b[(i + j) % n]){
                ok = false;
                break;
            }
        }
        if(ok){
            ans = min(ans, x);
        }
    }
    cout << ans;
}