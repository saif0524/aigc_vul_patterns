#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long T, n;
    cin >> T >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    vector<long long> sum(n);
    sum[0] = a[0];
    for(int i=1; i<n; i++) sum[i] = sum[i-1] + a[i];
    long long L = sum[n-1];
    vector<long long> res(n, 0);
    for(long long t=0; t<T; t++){
        int idx = 0;
        for(int i=1; i<n; i++){
            if(((t - sum[i] + L) % L) < ((t - sum[idx] + L) % L)) idx = i;
        }
        res[idx]++;
    }
    for(auto &x : res) cout << x << " ";
    cout << "\n";
}