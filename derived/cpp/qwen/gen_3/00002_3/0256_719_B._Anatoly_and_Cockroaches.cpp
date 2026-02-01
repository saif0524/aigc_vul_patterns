#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int b1=0, r1=0, b2=0, r2=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[i]=='b') b1++;
            else r1++;
        }
        else{
            if(s[i]=='b') b2++;
            else r2++;
        }
    }
    cout << min(b1+r2, b2+r1);
}