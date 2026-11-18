#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> perm(n);
    for(int i=0;i<n;i++) perm[i] = i+1;
    for(int k=n-1;k>=2;k--){
        int r = n / k;
        int rem = n % k;
        vector<int> new_perm(n);
        int idx = 0;
        for(int i=0;i<r;i++){
            for(int j=1;j<k;j++) new_perm[idx++] = perm[i*k+j];
            new_perm[idx++] = perm[i*k];
        }
        for(int i=0;i<rem;i++) new_perm[idx++] = perm[r*k+i];
        perm = new_perm;
    }
    for(int i=0;i<n;i++) cout << perm[i] << (i==n-1?"":" ");
    cout << "\n";
    return 0;
}