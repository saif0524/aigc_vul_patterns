#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    int open = 0, close = 0, need = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '(') open++;
        else if(s[i] == ')') close++;
        else{
            while(open + need <= close){
                need++;
                if(need > 100000){
                    cout << -1;
                    return 0;
                }
            }
            ans.push_back(need);
            close += need;
            need = 0;
        }
    }
    if(open + need != close){
        cout << -1;
        return 0;
    }
    for(int x: ans) cout << x << "\n";
}