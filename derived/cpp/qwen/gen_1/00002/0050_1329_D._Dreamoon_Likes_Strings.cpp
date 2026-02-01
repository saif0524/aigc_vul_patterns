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
        vector<pair<int,int>> res;
        for(int i=1;i<n;){
            int j = i;
            while(j < n && s[j] == s[j-1]) j++;
            if(j-i > 0){
                if((j-i) % 2 == 1){
                    res.push_back({i,i});
                    i++;
                }
                while(i < j){
                    res.push_back({i,i+1});
                    i += 2;
                }
            }
            else i++;
        }
        if(n % 2 == 1) res.push_back({n,n});
        cout << res.size() << "\n";
        for(auto [l,r] : res){
            cout << l << " " << r << "\n";
        }
    }
}