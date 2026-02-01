#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=1;i<=n;i++){
        p[i-1] = i;
    }
    for(int k=2;k<n;k++){
        for(int i=0;i<n;i+=k){
            int len = min(k, n-i);
            for(int j=0;j<len/2;j++){
                swap(p[i+j], p[i+len-1-j]);
            }
        }
    }
    reverse(p.begin(), p.end());
    for(int i=0;i<n;i++){
        cout << p[i] << (i==n-1?"":" ");
    }
    cout << "\n";
    return 0;
}