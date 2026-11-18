#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string T;
    cin >> T;
    int Q;
    cin >> Q;
    
    unordered_set<string> patterns;
    while (Q--) {
        string P;
        cin >> P;
        patterns.insert(P);
    }
    
    int n = T.size();
    for (const auto& P : patterns) {
        size_t found = T.find(P);
        if (found != string::npos) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}