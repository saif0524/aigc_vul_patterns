#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            char minc = min('a' + k - 1, s[i]);
            for(int j = min(i, n-1); j >= max(0, i-1); j--){
                if(s[j] != 'a'){
                    s[j] = min(s[j] - 1, minc);
                    break;
                }
            }
        }
        cout << s << "\n";
    }
}