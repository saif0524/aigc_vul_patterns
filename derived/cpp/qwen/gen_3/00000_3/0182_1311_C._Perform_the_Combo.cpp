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
        for(auto &x : p) cin >> x;
        vector<long long> cnt(26, 0);
        long long full = m+1;
        vector<long long> partial(n, 0);
        for(auto x : p) partial[x]++;
        for(int i = 1; i < n; i++) partial[i] += partial[i-1];
        for(int i = 0; i < n; i++){
            cnt[s[i]-'a'] += full - partial[i];
        }
        for(auto x : cnt) cout << x << " ";
        cout << "\n";
    }
}