#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int operations = 0;
    while(true){
        bool found = false;
        vector<bool> to_delete(n, false);
        for(int i=1; i<n-1; ++i){
            if(s[i] != s[i-1] && s[i] != s[i+1]){
                to_delete[i] = true;
                found = true;
            }
        }
        if(s.size() > 1){
            if(s[0] != s[1]){
                to_delete[0] = true;
                found = true;
            }
            if(s[n-1] != s[n-2]){
                to_delete[n-1] = true;
                found = true;
            }
        }
        if(!found) break;
        string new_s;
        for(int i=0; i<n; ++i){
            if(!to_delete[i]){
                new_s += s[i];
            }
        }
        s = new_s;
        n = s.size();
        operations++;
    }
    cout << operations << "\n";
}