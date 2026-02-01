#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
                ans++;
                s[i] = 'a';
                if(i+1 < n && s[i+1] == s[i]){
                    s[i] = 'b';
                }
            }
        }
        cout << ans << "\n";
    }
}