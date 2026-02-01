#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n-1; i++){
        if(s[i] > s[i+1]){
            cout << "YES\n";
            cout << i+1 << " " << i+2;
            return 0;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(s[i] < s[i+1]){
            for(int j = n-1; j > i; j--){
                if(s[j] < s[i]){
                    cout << "YES\n";
                    cout << i+1 << " " << j+1;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}