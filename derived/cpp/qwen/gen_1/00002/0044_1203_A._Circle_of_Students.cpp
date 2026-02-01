#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int &x : p) cin >> x;
        bool clockwise = true, counterclockwise = true;
        for(int i=0; i<n; ++i){
            if(p[i] != (p[(i+1)%n] + 1) % n) clockwise = false;
            if(p[i] != (p[(i+n-1)%n] - 1 + n) % n) counterclockwise = false;
        }
        if(clockwise || counterclockwise) cout << "YES\n";
        else cout << "NO\n";
    }
}