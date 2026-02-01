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
        int changes = 0;
        for(int i=1; i<n-1; i++){
            if(s[i-1] == s[i] && s[i] == s[i+1]){
                changes++;
                s[i+1] = 'a';
                for(char c = 'a'; c <= 'z'; c++){
                    if(c != s[i-1] && c != s[i]){
                        s[i+1] = c;
                        break;
                    }
                }
            }
        }
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                changes++;
            }
        }
        cout << changes << "\n";
    }
}