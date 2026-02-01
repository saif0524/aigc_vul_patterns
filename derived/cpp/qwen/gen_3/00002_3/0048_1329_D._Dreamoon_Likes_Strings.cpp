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
        vector<pair<int,int>> steps;
        for(int i=0; i<n; ){
            int j = i;
            while(j+1 < n && s[j] == s[j+1]) j++;
            if(j-i+1 >= 2){
                steps.push_back({i+1, j});
                i = j+1;
            } else {
                i++;
            }
        }
        for(int i=0; i<n;){
            int j = i;
            while(j+1 < n && s[j] == s[j+1]) j++;
            if(j-i+1 == 1){
                steps.push_back({i+1, i+1});
                i = j+1;
            } else {
                i = j+1;
            }
        }
        cout << steps.size() << "\n";
        for(auto p: steps){
            cout << p.first << " " << p.second << "\n";
        }
    }
}