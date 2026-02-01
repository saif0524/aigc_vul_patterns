#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for(char c : s){
            if(c == '0') cnt0++;
            else cnt1++;
        }
        if(cnt0 % 2 == 0 && cnt1 % 2 == 0){
            cout << "NET\n";
        }
        else{
            cout << "DA\n";
        }
    }
}