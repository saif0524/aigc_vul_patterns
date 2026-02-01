#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt=0;
    for(char c:s){
        if(c=='+') cnt++;
        else cnt--;
        if(cnt<0){
            cout << "No";
            return 0;
        }
    }
    if(cnt!=0) cout << "No";
    else cout << "Yes";
}