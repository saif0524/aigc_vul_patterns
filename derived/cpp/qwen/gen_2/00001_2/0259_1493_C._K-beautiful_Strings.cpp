#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans = s;
        bool found = false;
        while(true){
            bool valid = true;
            int cnt[26] = {0};
            for(char c : ans) cnt[c-'a']++;
            for(int i=0; i<26; i++){
                if(cnt[i] % k != 0){
                    valid = false;
                    break;
                }
            }
            if(valid){
                found = true;
                break;
            }
            int pos = n-1;
            while(pos >= 0 && ans[pos] == 'z'){
                pos--;
            }
            if(pos < 0){
                break;
            }
            ans[pos]++;
            for(int i=pos+1; i<n; i++){
                ans[i] = 'a';
            }
        }
        if(found){
            cout << ans << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}