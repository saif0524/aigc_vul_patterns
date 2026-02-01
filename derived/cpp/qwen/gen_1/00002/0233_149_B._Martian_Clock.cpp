#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int colon = s.find(':');
    string a = s.substr(0, colon);
    string b = s.substr(colon + 1);
    auto convert = [](const string &s, int base){
        long long res = 0;
        for(char c : s){
            if(c >= '0' && c <= '9') res = res * base + (c - '0');
            else res = res * base + (c - 'A' + 10);
            if(res > 24 * 60) return -1;
        }
        return (int)res;
    };
    int max_base = 2;
    for(char c : a){
        if(c >= '0' && c <= '9') max_base = max(max_base, c - '0' + 1);
        else max_base = max(max_base, c - 'A' + 11);
    }
    for(char c : b){
        if(c >= '0' && c <= '9') max_base = max(max_base, c - '0' + 1);
        else max_base = max(max_base, c - 'A' + 11);
    }
    vector<int> possible_bases;
    for(int base = max_base; base <= 36; base++){
        int hours = convert(a, base);
        int minutes = convert(b, base);
        if(hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59){
            possible_bases.push_back(base);
        }
    }
    if(possible_bases.empty()){
        cout << 0;
    } else if(possible_bases.back() == 36){
        cout << -1;
    } else {
        for(int i = 0; i < possible_bases.size(); i++){
            cout << possible_bases[i];
            if(i < possible_bases.size() - 1) cout << " ";
        }
    }
    return 0;
}