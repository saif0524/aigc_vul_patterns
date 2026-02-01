#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i=0;
    vector<string> res;
    while(i<n){
        int c0=0, c1=0;
        string temp;
        while(i<n && (c0==0 || c1==0 || c0!=c1)){
            temp+=s[i];
            if(s[i]=='0') c0++;
            else c1++;
            i++;
        }
        res.push_back(temp);
    }
    cout << res.size() << "\n";
    for(auto x: res) cout << x << " ";
    return 0;
}