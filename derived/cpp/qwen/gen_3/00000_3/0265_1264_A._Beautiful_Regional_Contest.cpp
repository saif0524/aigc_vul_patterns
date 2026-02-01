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
        for(int &x: p) cin >> x;
        int g=0, s=0, b=0;
        for(int i=0;i<n-2 && (g+s+b)<=n/2;){
            if(p[i]>p[i+1] && p[i+1]>p[i+2]){
                g = 1;
                s = 1;
                b = 1;
                int j = i+3;
                while(j<n && p[j-1]>p[j] && (g+s+b)<=n/2){
                    if(b==s){
                        b++;
                    }else{
                        s++;
                    }
                    j++;
                }
                break;
            }
            i++;
        }
        if((g+s+b) > n/2){
            g=0,s=0,b=0;
        }
        cout << g << " " << s << " " << b << "\n";
    }
}