#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--){
        int m;
        char c;
        cin >> m >> c;
        int ans = 0, cnt = 0, l = 0;
        for(int r = 0; r < n; ++r){
            if(s[r] != c) cnt++;
            while(cnt > m){
                if(s[l] != c) cnt--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << "\n";
    }
}