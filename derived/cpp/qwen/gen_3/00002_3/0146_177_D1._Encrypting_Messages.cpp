#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n), b(m);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    vector<int> dif(n+1, 0);
    for(int i=0;i<m;i++){
        dif[i] += b[i];
        dif[i+m] -= b[i];
    }
    for(int i=1;i<=n;i++){
        dif[i] += dif[i-1];
        a[i-1] = (a[i-1] + dif[i-1]) % c;
        if(a[i-1] < 0) a[i-1] += c;
    }
    for(int i=0;i<n;i++) cout << a[i] << (i==n-1?"":" ");
}