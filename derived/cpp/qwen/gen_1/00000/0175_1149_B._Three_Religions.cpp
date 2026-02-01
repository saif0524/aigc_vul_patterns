#include <bits/stdc++.h>
using namespace std;

bool canCoexist(const string& s, const string& r1, const string& r2, const string& r3) {
    int n = s.size();
    int i1 = 0, i2 = 0, i3 = 0;
    
    for (char c : s) {
        if (i1 < r1.size() && c == r1[i1]) i1++;
        if (i2 < r2.size() && c == r2[i2]) i2++;
        if (i3 < r3.size() && c == r3[i3]) i3++;
    }
    
    return i1 == r1.size() && i2 == r2.size() && i3 == r3.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    string r1, r2, r3;
    for(int i = 0; i < q; i++){
        char type;
        cin >> type;
        if(type == '+'){
            int idx;
            char c;
            cin >> idx >> c;
            if(idx == 1) r1 += c;
            else if(idx == 2) r2 += c;
            else r3 += c;
        }else{
            int idx;
            cin >> idx;
            if(idx == 1) r1.pop_back();
            else if(idx == 2) r2.pop_back();
            else r3.pop_back();
        }
        
        if(canCoexist(s, r1, r2, r3)) cout << "YES\n";
        else cout << "NO\n";
    }
}