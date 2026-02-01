#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int balance = 0;
    vector<pair<int,int>> ops;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            balance++;
        } else {
            if(balance > 0){
                ops.push_back({i-balance+1, i});
                balance--;
            }
        }
    }
    cout << ops.size() << "\n";
    for(auto& op : ops){
        cout << 2 << "\n";
        cout << op.first+1 << " " << op.second+1 << "\n";
    }
}