#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    
    int minInk = INT_MAX;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int ink = 0;
            for(int k=0; k<m/2; ++k){
                ink += (a[i%a.size()] % n) + (b[j%b.size()] % n);
                i = (i+1)%n;
                j = (j-1+n)%n;
            }
            minInk = min(minInk, ink);
        }
    }
    
    cout << minInk * (m/2);
    return 0;
}