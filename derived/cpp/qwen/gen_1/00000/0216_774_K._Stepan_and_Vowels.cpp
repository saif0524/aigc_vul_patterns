#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 0){
        cout << s;
        return 0;
    }
    string result;
    result += s[0];
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i-1] && (s[i] == 'e' || s[i] == 'o')){
            int count = 1;
            while(i < n && s[i] == s[i-1]){
                ++count;
                ++i;
            }
            if(count == 2){
                result += s[i-1];
                result += s[i-1];
            }
            else{
                result += s[i-1];
                --i;
            }
        }
        else if(i > 1 && s[i] == s[i-1] && s[i] == s[i-2]){
            continue;
        }
        else{
            result += s[i];
        }
    }
    cout << result;
}