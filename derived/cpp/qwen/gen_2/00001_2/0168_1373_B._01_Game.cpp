#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int zero = 0, one = 0;
        for(char c : s){
            if(c == '0') zero++;
            else one++;
        }
        if(abs(zero - one) >= 1){
            cout << "DA\n";
        }
        else{
            cout << "NET\n";
        }
    }
}