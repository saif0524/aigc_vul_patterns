#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int pos = s.find(':');
    string a = s.substr(0, pos);
    string b = s.substr(pos+1, s.size()-pos-1);
    
    int max_a = 0, max_b = 0;
    for(char c: a) max_a = max(max_a, (int)(c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10));
    for(char c: b) max_b = max(max_b, (int)(c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10));
    
    if(max_a >= 60 || max_b >= 60){
        cout << 0;
        return 0;
    }
    
    int inf = 1;
    for(int r = max(max_a, max_b) + 1; r <= 36; ++r){
        long long num_a = 0, num_b = 0;
        bool valid = true;
        for(int i = 0; i < a.size(); ++i){
            num_a = num_a * r + (a[i] >= '0' && a[i] <= '9' ? a[i] - '0' : a[i] - 'A' + 10);
            if(num_a > 24) valid = false;
        }
        for(int i = 0; i < b.size(); ++i){
            num_b = num_b * r + (b[i] >= '0' && b[i] <= '9' ? b[i] - '0' : b[i] - 'A' + 10);
            if(num_b > 59) valid = false;
        }
        if(valid && num_a < 24 && num_b < 60){
            if(r == 36) inf = 0;
            cout << r << ' ';
        }
    }
    if(inf) cout << -1;
    return 0;
}