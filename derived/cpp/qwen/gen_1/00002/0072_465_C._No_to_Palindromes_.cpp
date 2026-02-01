#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    string s;
    cin >> n >> p >> s;
    for(int i = n-1; i >= 0; i--){
        if(s[i] < 'a' + p - 1){
            s[i]++;
            bool valid = true;
            for(int j = 1; j <= i && valid; j++){
                if(s[i] == s[i-j]) valid = false;
                if(i-j-1 >= 0 && s[i-j] == s[i-j-1]) valid = false;
            }
            if(valid){
                for(int j = i+1; j < n; j++){
                    for(char c = 'a'; c <= 'a'+p-1; c++){
                        bool can_use = true;
                        for(int k = 1; k <= j && can_use; k++){
                            if(c == s[j-k]) can_use = false;
                            if(j-k-1 >= 0 && s[j-k-1] == c) can_use = false;
                        }
                        if(can_use){
                            s[j] = c;
                            break;
                        }
                    }
                }
                cout << s;
                return 0;
            }
        }
    }
    cout << "NO";
}