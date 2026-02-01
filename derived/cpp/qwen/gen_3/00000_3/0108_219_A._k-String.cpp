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
    map<char, int> freq;
    for(char c : s){
        freq[c]++;
    }
    string block;
    for(auto [c, cnt] : freq){
        if(cnt % k != 0){
            cout << "-1";
            return 0;
        }
        block += string(cnt / k, c);
    }
    string result;
    for(int i = 0; i < k; ++i){
        result += block;
    }
    cout << result;
}