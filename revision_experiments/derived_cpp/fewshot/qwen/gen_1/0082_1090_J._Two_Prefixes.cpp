#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    
    unordered_set<string> distinctStrings;
    
    int n = s.size();
    int m = t.size();
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            distinctStrings.insert(s.substr(0, i) + t.substr(0, j));
        }
    }
    
    cout << distinctStrings.size() << endl;
    
    return 0;
}