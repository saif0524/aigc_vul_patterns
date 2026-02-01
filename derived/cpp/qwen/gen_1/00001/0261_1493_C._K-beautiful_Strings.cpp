#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool found = false;
        for(int i = n-1; i >= 0; --i){
            if(s[i] < 'z'){
                char next_char = s[i] + 1;
                string new_s = s.substr(0, i) + next_char;
                string remaining = string(n - i - 1, 'a');
                new_s += remaining;
                int freq[26] = {0};
                for(char c : new_s){
                    freq[c - 'a']++;
                }
                bool valid = true;
                for(int f : freq){
                    if(f % k != 0){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    found = true;
                    cout << new_s << "\n";
                    break;
                }
            }
        }
        if(!found){
            cout << "-1\n";
        }
    }
}