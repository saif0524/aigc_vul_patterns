#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    int open = 0, close =0, hash = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') open++;
        else if(s[i]==')') close++;
        else hash++;
    }
    if(open!=close+hash){
        cout << -1;
        return 0;
    }
    open = 0, close = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') open++;
        else if(s[i]==')'){
            close++;
            if(close>open){
                cout << -1;
                return 0;
            }
        }
        else{
            int need = open-close+1;
            if(need<=0){
                cout << -1;
                return 0;
            }
            ans.push_back(need);
            close+=need;
        }
    }
    if(open!=close){
        cout << -1;
        return 0;
    }
    for(auto x:ans){
        cout << x << "\n";
    }
}