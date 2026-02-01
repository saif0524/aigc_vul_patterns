#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(auto &x: p) cin >> x;
        int g = 0, s = 0, b = 0;
        for(int i=0; i<n; ++i){
            if(g==0 && (i+1)*2<=n){
                g = 1;
                continue;
            }
            if(g>0 && s<g && (i+1)*2<=n && p[i]<p[i-g]){
                s = g;
                continue;
            }
            if(s>0 && b<g && (i+1)*2<=n && p[i]<p[i-s]){
                b = g;
                continue;
            }
            if(g>0 && s>0 && b>0 && (i+1)*2<=n && p[i]<p[i-b]){
                b++;
                if(b>=s){
                    g++;
                    s = b;
                    b = g;
                }
            }
        }
        if(g==0 || s==0 || b==0 || g>=s || g>=b){
            cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
        }
        else{
            cout << g << ' ' << s << ' ' << b << '\n';
        }
    }
}