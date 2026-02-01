#include <bits/stdc++.h>
using namespace std;

bool is_valid(const string& s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) return false;
    }
    return bal == 0;
}

string fix_brackets(const string& s) {
    int n = s.size();
    int bal = 0;
    int open_excess = 0, close_excess = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) {
            bal = 0;
            close_excess++;
        }
    }
    open_excess = bal;
    
    string fixed;
    bal = 0;
    for (char c : s) {
        if (c == '(') {
            if (open_excess > 0) {
                open_excess--;
            } else {
                fixed += c;
                bal++;
            }
        } else {
            if (bal > 0) {
                fixed += c;
                bal--;
            } else {
                close_excess--;
            }
        }
    }
    return fixed;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s = fix_brackets(s);
    
    string best = s;
    for(int i=0; i<s.size(); i++){
        rotate(s.rbegin(), s.rbegin()+1, s.rend());
        s = fix_brackets(s);
        if(s < best) best = s;
    }
    cout << best;
}