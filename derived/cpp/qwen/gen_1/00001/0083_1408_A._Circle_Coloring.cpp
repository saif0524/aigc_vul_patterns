#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        for(int &x : c) cin >> x;
        vector<int> p(n);
        for(int i=0; i<n; ++i){
            if(i==0){
                if(a[i] != b[(i+1)%n]) p[i] = a[i];
                else p[i] = b[i];
            }
            else{
                if(a[i] != p[i-1]) p[i] = a[i];
                else if(b[i] != p[i-1]) p[i] = b[i];
                else p[i] = c[i];
            }
        }
        for(int x : p) cout << x << " ";
        cout << "\n";
    }
}