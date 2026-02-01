#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    if(n % k != 0){
        cout << "-1";
        return 0;
    }
    int len = n / k;
    vector<int> freq(26, 0);
    for(char c : s) freq[c - 'a']++;
    for(int i = 0; i < 26; i++){
        if(freq[i] % k != 0){
            cout << "-1";
            return 0;
        }
        freq[i] /= k;
    }
    string result;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < 26; j++){
            if(freq[j] > 0){
                result += (char)('a' + j);
                freq[j]--;
            }
        }
    }
    for(int i = 0; i < k; i++) cout << result;
}