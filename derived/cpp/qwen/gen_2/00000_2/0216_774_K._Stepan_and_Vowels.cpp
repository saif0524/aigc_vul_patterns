#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    string result;
    result += s[0];
    for(int i=1;i<n;i++){
        if(s[i] == result.back() && (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'y')){
            continue;
        }
        if(s[i] == result.back() && (s[i] == 'e' || s[i] == 'o')){
            if(i > 1 && s[i] == s[i-1]) continue;
            else result += s[i];
        } else {
            result += s[i];
        }
    }
    cout << result;
}