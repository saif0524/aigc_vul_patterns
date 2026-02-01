#include <bits/stdc++.h>
using namespace std;

string solve(const string& s, const string& c) {
    string t = s;
    int n = s.size();
    int m = c.size();
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(t[i], t[j]);
            if (t < c) {
                found = true;
                break;
            }
            swap(t[i], t[j]);
        }
        if (found) break;
    }
    
    if (!found && s < c) {
        return s;
    }
    
    return found ? t : "---";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s, c;
        cin >> s >> c;
        cout << solve(s, c) << "\n";
    }
}