#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    while(true){
        bool found = false;
        vector<bool> to_delete(n, false);
        for(int i=1; i<n-1; i++){
            if(!to_delete[i] && (s[i] != s[i-1] || s[i] != s[i+1])){
                if(s[i] == s[i-1]) to_delete[i-1] = true;
                if(s[i] == s[i+1]) to_delete[i+1] = true;
                found = true;
            }
        }
        if(s.size() >= 2){
            if(!to_delete[0] && s[0] != s[1]){
                to_delete[1] = true;
                found = true;
            }
            if(!to_delete[n-1] && s[n-1] != s[n-2]){
                to_delete[n-2] = true;
                found = true;
            }
        }
        if(!found) break;
        string new_s;
        for(int i=0; i<n; i++){
            if(!to_delete[i]) new_s += s[i];
        }
        s = new_s;
        n = s.size();
        ans++;
    }
    cout << ans;
}