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
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
                ans++;
                s[i] = 'a';
                for(char c='b';c<='z';c++){
                    if(c!=s[i-1]&&(i+1>=n||c!=s[i+1])){
                        s[i] = c;
                        break;
                    }
                }
            }
            if(i>=2&&s[i-2]==s[i]){
                ans++;
                s[i] = 'a';
                for(char c='b';c<='z';c++){
                    if(c!=s[i-1]&&c!=s[i-2]){
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}