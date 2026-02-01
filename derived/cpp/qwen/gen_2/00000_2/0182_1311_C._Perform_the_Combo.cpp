#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> p(m);
        for(auto &x: p) cin >> x;
        vector<long long> cnt(26, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < p[i]; ++j){
                cnt[s[j]-'a']++;
            }
        }
        for(int i = 0; i < n; ++i){
            cnt[s[i]-'a']++;
        }
        for(auto x: cnt) cout << x << " ";
        cout << "\n";
    }
}