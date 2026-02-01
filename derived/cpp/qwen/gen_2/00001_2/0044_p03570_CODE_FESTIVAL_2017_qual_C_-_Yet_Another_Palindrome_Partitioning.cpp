#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int freq[26] = {0};
    for(char c : s){
        freq[c - 'a']++;
    }
    int odd_count = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] % 2 != 0){
            odd_count++;
        }
    }
    cout << max(1, odd_count) << endl;
}