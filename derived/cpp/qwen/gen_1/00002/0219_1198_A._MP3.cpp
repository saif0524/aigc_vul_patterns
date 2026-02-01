#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long I;
    cin >> n >> I;
    I *= 8;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();
    if(m == 1){
        cout << 0;
        return 0;
    }
    int ans = n;
    for(int i=0; i<m; i++){
        int l = a[i];
        int k = 1;
        for(k=1; (1<<k) < m-i; k++);
        if(1LL * n * k <= I){
            ans = min(ans, i + (m - (i + (1<<k))) );
        }
    }
    for(int i=0; i<m; i++){
        int r = a[i];
        int k=1;
        for(k=1; (1<<k) < i+1; k++);
        if(1LL * n * k <= I){
            ans = min(ans, (m - (i + 1)) + i - (1<<k) + 1);
        }
    }
    cout << ans;
    return 0;
}