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
        int cnt0 =0, cnt1 = 0;
        for(auto c : s){
            if(c == '0') cnt0++;
            else cnt1++;
        }
        if(cnt0 % 2 == 0 && cnt1 % 2 == 0) cout << "NET\n";
        else if(cnt0 % 2 == 1 && cnt1 % 2 == 1) cout << "NET\n";
        else cout << "DA\n";
    }
    return 0;
}