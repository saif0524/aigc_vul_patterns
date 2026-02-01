#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt1 = 0, cnt0 = 0;
    vector<string> ans;
    string current;
    for(char c : s){
        current += c;
        if(c == '1') cnt1++;
        else cnt0++;
        if(cnt1 != 0 && cnt0 != 0 && cnt1 == cnt0){
            ans.push_back(current);
            current.clear();
            cnt1 = 0, cnt0 = 0;
        }
    }
    if(!current.empty()) ans.push_back(current);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    cout << "\n";
}