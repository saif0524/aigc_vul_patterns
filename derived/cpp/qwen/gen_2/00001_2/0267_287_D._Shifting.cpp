#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i] = i+1;
    for(int k=2;k<=n;k++){
        vector<int> f(n);
        int r = 1;
        while(pow(k, r) <= n) r++;
        r--;
        int pos = 0;
        for(int j=1;j<=r;j++){
            int len = pow(k, j);
            for(int x=1;x<=len;x++){
                f[pos++] = p[x + (len-1) * (j-1)];
            }
        }
        int rem = n - pow(k, r);
        for(int x=1;x<=rem;x++){
            f[pos++] = p[pow(k, r) + x - 1];
        }
        p = f;
    }
    for(int i=0;i<n;i++) cout << p[i] << (i < n-1 ? ' ' : '\n');
}