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
        int g=0,s=0,b=0;
        for(int i=0;i<n;i++){
            if(g==0 && i+1<=n/2 && (i+1==n-1 || p[i]>p[i+1])) g++;
            else if(s==0 && g>0 && i+1<=n/2 && (i+1==n-1 || p[i]>p[i+1])) s++;
            else if(b==0 && s>0 && g>0 && i+1<=n/2 && (i+1==n-1 || p[i]>p[i+1])) b++;
            else if(g>0 && s>0 && b>0 && i+1<=n/2 && (i+1==n-1 || p[i]>p[i+1])){
                if(g<s && g<b) b++;
                else if(s<b) s++;
                else g++;
            }
            else break;
        }
        if(g==0 || s==0 || b==0) g=s=b=0;
        cout << g << " " << s << " " << b << "\n";
    }
}