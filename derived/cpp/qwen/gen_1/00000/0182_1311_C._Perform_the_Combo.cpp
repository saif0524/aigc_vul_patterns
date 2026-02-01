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
        for(int &x: p) cin >> x;
        vector<long long> freq(26, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < p[i]; j++){
                freq[s[j]-'a']++;
            }
        }
        for(int j = 0; j < n; j++){
            freq[s[j]-'a']++;
        }
        for(auto x: freq) cout << x << " ";
        cout << "\n";
    }
}