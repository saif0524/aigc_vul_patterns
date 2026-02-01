#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int &x: p) cin >> x;
        bool clockwise=true, counterclockwise=true;
        for(int i=0; i<n; ++i){
            if(p[i] != (i+1) % n + 1) clockwise = false;
            if(p[i] != (i-1+n) % n + 1) counterclockwise = false;
        }
        if(clockwise || counterclockwise) cout << "YES\n";
        else cout << "NO\n";
    }
}