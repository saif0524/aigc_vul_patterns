#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    map<char, int> freq_s, freq_t;
    for(char c : s) freq_s[c]++;
    for(char c : t) freq_t[c]++;
    string res;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            bool found = false;
            for(char c = 'a'; c <= 'z'; c++){
                if(freq_s[c] > 0){
                    bool valid = true;
                    for(char x = c + 1; x <= 'z'; x++){
                        if(freq_t[x] > 0){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        res += c;
                        freq_s[c]--;
                        found = true;
                        break;
                    }
                }
            }
            if(!found){
                for(char c = 'z'; c >= 'a'; c--){
                    if(freq_s[c] > 0){
                        res += c;
                        freq_s[c]--;
                        break;
                    }
                }
            }
        }
        else{
            bool found = false;
            for(char c = 'z'; c >= 'a'; c--){
                if(freq_t[c] > 0){
                    bool valid = true;
                    for(char x = 'a'; x < c; x++){
                        if(freq_s[x] > 0){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        res += c;
                        freq_t[c]--;
                        found = true;
                        break;
                    }
                }
            }
            if(!found){
                for(char c = 'a'; c <= 'z'; c++){
                    if(freq_t[c] > 0){
                        res += c;
                        freq_t[c]--;
                        break;
                    }
                }
            }
        }
    }
    cout << res;
}