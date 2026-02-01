#include <bits/stdc++.h>
using namespace std;

string solve(const string& s, const string& c) {
    int n = s.size();
    string result = s;
    bool found = false;
    for (int i = 0; i < n && !found; ++i) {
        for (int j = i + 1; j < n && !found; ++j) {
            string t = s;
            swap(t[i], t[j]);
            if (t < c) {
                result = t;
                found = true;
            }
        }
    }
    return found ? result : (s < c ? s : "---");
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