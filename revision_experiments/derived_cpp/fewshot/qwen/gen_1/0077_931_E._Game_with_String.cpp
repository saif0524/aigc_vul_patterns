#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z(n);
    for(int i=1, l=0, r=0; i<n; ++i){
        if(i<=r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if(i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    map<char, vector<int>> mp;
    for(int i=0;i<n;++i) mp[s[i]].push_back(i);
    double ans = 0;
    for(auto &[c, vec] : mp){
        int m = vec.size();
        if(m==1){
            ans += 1.0;
            continue;
        }
        int cnt = 0;
        for(int i=1;i<m;++i){
            int d = vec[i] - vec[i-1];
            if(d!=z[d]) ++cnt;
        }
        if(cnt==0) ans += 1.0;
        else if(cnt==1) ans += 0.5;
    }
    ans /= n;
    cout << fixed << setprecision(12) << ans;
}