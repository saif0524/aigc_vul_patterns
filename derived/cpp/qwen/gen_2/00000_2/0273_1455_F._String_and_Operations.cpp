#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i = 0; i < n; ++i){
            s[i] = 'a';
        }
        cout << s << "\n";
    }
}