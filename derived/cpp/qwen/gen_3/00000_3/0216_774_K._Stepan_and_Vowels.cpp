#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res;
    for(int i=0;i<n;i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y'){
            if(i+1 < n && s[i] == s[i+1]){
                if(s[i] == 'e' && i+2 < n && s[i+2] == s[i+1]) i+=2;
                else if(s[i] == 'o' && i+2 < n && s[i+2] == s[i+1]) i+=2;
                else i+=1;
            }
        }
        res += s[i];
    }
    cout << res;
}