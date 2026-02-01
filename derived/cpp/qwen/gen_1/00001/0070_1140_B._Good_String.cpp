#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n-1;
        for(int i=0; i<n; i++){
            int l=0, r=0;
            int del = 0;
            for(int j=i; j<n; j++){
                if(s[j] == '>') r++;
                else l++;
                if(l > r){
                    del = j-i+1;
                    break;
                }
            }
            if(l == r) ans = min(ans, del);
        }
        for(int i=0; i<n; i++){
            int l=0, r=0;
            int del = 0;
            for(int j=i; j>=0; j--){
                if(s[j] == '>') r++;
                else l++;
                if(r < l){
                    del = i-j+1;
                    break;
                }
            }
            if(l == r) ans = min(ans, del);
        }
        cout << ans << endl;
    }
}