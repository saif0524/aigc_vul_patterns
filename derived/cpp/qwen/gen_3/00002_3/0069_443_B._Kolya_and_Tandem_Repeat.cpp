#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    int max_l = 0;
    for(int l=1; l<=n+k; l++){
        bool possible = true;
        for(int i=0; i<l && possible; i++){
            if(i + l < n && s[i] != s[i + l]){
                possible = false;
            }
        }
        if(possible){
            int full_repeats = (n + k) / l;
            if(full_repeats >= 2){
                max_l = l;
            }
        }
    }
    cout << max_l;
}