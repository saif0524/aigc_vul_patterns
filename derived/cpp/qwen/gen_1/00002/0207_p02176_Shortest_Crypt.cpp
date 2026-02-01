#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;
    int dx=0, dy=0;
    for(char c:S){
        if(c>='A'&&c<='M') dy++;
        else if(c>='N'&&c<='Z') dy--;
        else if(c>='a'&&c<='m') dx++;
        else if(c>='n'&&c<='z') dx--;
    }
    string ans="";
    for(int i=0;i<abs(dy);i++){
        if(dy>0) ans+='A';
        else ans+='N';
    }
    for(int i=0;i<abs(dx);i++){
        if(dx>0) ans+='a';
        else ans+='n';
    }
    cout << ans.size() << "\n";
    cout << ans << "\n";
}