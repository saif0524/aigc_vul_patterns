#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    long long ans_y = LLONG_MAX, ans_z = -1;
    for(int i=0;i<n;i++){
        if(i && a[i] == a[i-1]) continue;
        long long z = a[0] - a[i];
        if(z == 0) continue;
        long long y = 0;
        for(int j=0;j<n;j++){
            y += (a[j]/z) + (a[j]%z != 0);
        }
        if(y < ans_y){
            ans_y = y;
            ans_z = z;
        }
    }
    cout << ans_y << " " << ans_z << "\n";
}